module tttop(
		SW, 
		LEDR, 
		CLOCK_50,						//	On Board 50 MHz
		KEY
		);
	input [9:0]SW;
	input [3:0]KEY;
	input CLOCK_50;
	output [9:0]LEDR;

	wire [7:0]xout;
	wire [6:0]yout;
	
	mainControl(SW, KEY, xout, yout, CLOCK_50, LEDR);
	

endmodule



module detectMove(dataIn, movecmd);
	input [3:0]dataIn;
	output reg movecmd;
	
	always@(*)begin
		if(dataIn[0] == 1 ||dataIn[1] == 1 ||dataIn[2] == 1 ||dataIn[3] == 1) movecmd = 1;
		else movecmd = 0;
	end
endmodule



module mainControl(	
		SW,
		KEY,
		xout,
		yout,
		clock,
		LEDR
);
	input [9:0]SW;
	input [3:0]KEY;
	input clock;
	output reg[9:0]LEDR;
	output reg [7:0]xout;
	output reg [6:0]yout;
	
	initial begin
		xout = 8'b0;
		yout = 7'b0;
		now = 4'b0000;
		next = 4'b0000;
	end
	
	
	//wire and path
	reg domove;
	wire finishMove, newC, movecmd;

	detectMove(SW[3:0], movecmd);
	newClock(clock, newC);
	wire[4:0] temp;
	move(SW[3:0], domove, finishMove, clock, temp[4:0]);
	
	reg [3:0] now, next;
	parameter sleep = 4'b0000, move = 4'b0001;
	
	//center FHS
	always @(*)begin
		LEDR[8:4] = temp[4:0];
		case(now)
			sleep:begin
				if(movecmd == 1) next = move;
				else next = sleep;
				domove = 0;
				LEDR[1:0] =  2'b01;
			end
			move:begin
				if(SW[9] == 1) next = sleep;
				else next = move;
				domove = 1;
				LEDR[1:0] =  2'b10;
			end
			default: next = sleep;
		endcase
	end
	
	

	always@(posedge newC) now = next;
	
endmodule

module newClock(cin, cout);
	input cin;
	output reg cout;
	
	reg [28:0]count;
	
	always @(posedge cin) begin
		if (count == 0) begin
			count <= 26'd4999999;
			cout <= 1;
		end 
		else begin
			count <= count - 1;
			cout <= 0;
		end
	end
endmodule 


module move(dataIn, domove, finishmove, clock, LEDR);
	input [3:0]dataIn;
	input domove, clock;
	output reg finishmove;
	output reg [4:0]LEDR;
	
	reg go, back;
	reg [3:0]now, next, direct;
	parameter sleep = 4'b0000, findDirect = 4'b0001, move = 4'b0010;
	
	//control
	always@(*)begin
		case(now)
			sleep:begin
				if(domove == 1) next = findDirect;
				else next = sleep;
				direct = 0;
				go = 0;
				//LEDR[4:0] = 5'b00001; 
			end
			findDirect:begin
				if(dataIn[0] == 1) direct = 1;
				else if(dataIn[1] == 1) direct = 2;
				else if(dataIn[2] == 1) direct = 3;
				else if(dataIn[3] == 1) direct = 4;
				else direct = 0;
				next = move;
				//LEDR[4:0] = 5'b00010; 
			end
			move:begin
				if(back == 1) next = sleep;
				else next = move;
				go = 1;
				//LEDR[4:0] = 5'b00100; 
			end
			default: next = sleep;
		endcase
	end
	
	//datapath
	always@(*)begin
		if(go == 1)begin
			if(direct == 0) LEDR[4:0] = 5'b00001;
			if(direct == 1) LEDR[4:0] = 5'b00010;
			if(direct == 2) LEDR[4:0] = 5'b00100;
			if(direct == 3) LEDR[4:0] = 5'b01000;
			if(direct == 4) LEDR[4:0] = 5'b10000;
		end
		else begin 
			back = 0;
			LEDR[4:0] = 5'b00000;
		end
	end
	
	always@(posedge clock) now = next;
endmodule 

//module moveControl(direct, domove, finishmove);
//	input [3:0]direct;
//	input domove;
//	output reg finishmove;
//	
//	
//
//end

