#include <bits/stdc++.h>
using namespace std;

string hexToBinary(char a){

            if( a == '0'){
                return "0000";
            }
                
            else if( a == '1'){
                return "0001";
            }
            else if( a =='2'){
                return "0010";
            }  
            else if( a =='3'){
                return "0011";
            }    
            else if( a =='4'){
                return "0100";
            }    
            else if( a =='5'){
                return "0101";
            }  
            else if( a =='6'){
                return "0110";
            }
            else if( a =='7'){
                return "0111";
            }
            else if( a =='8'){
                return "1000";
            }
            else if( a =='9'){
                return "1001";
            }
            else if( a == 'A' || a == 'a'){
                return "1010";
                }
            else if( a == 'B' || a == 'b'){
                return "1011";
                }
            else if( a == 'C' || a == 'c'){
                return "1100";
                }
            else if( a == 'D' || a == 'd'){
                return "1101";
                }
            else if( a == 'E' || a == 'e'){
                return "1110";
                }
            else if( a == 'F' || a == 'f'){
                return "1111";
            }
        return 0;
}
int binaryToDecimal(string input) 
{   
    int decimalValue = 0;
    
    for (int i = input.length(); i >=0 ; i--)        
    {
        if(input[i] == '1'){
            decimalValue = decimalValue + pow(2,input.length()-i-1);
        }
    }  
  
    return decimalValue; 
}
int twosComplementToDecimal(string input) {
    int result = 0;

    if(input[0] == '1'){
        result = -1*pow(2,(input.length() - 1));
    }

    for (int i = 1; i < input.length(); i++) {
        if (input[i] == '1') {
            result = result + (pow(2, input.length()-1-i));
        }
    }

    return result;
}
string J_type(string input){
    string Binary = hexToBinary(input[0]) + hexToBinary(input[1]) + hexToBinary(input[2]) + hexToBinary(input[3]) + hexToBinary(input[4]) + hexToBinary(input[5]) + hexToBinary(input[6]) + hexToBinary(input[7]);
    string rd = Binary.substr(20,5);
    string imm = Binary.substr(0,1) + Binary.substr(12,8) + Binary.substr(11,1) + Binary.substr(1,10) ;
    string jumpFunc = "L1" ;

    cout << "jal " << "x" << binaryToDecimal(rd) << ", " << jumpFunc << endl;

    //cout << imm << endl ;
    //returning a string that contains both the immediate value as well as the name of the function to jump to

    string returnValue = imm + jumpFunc;
    return returnValue ;
}
void U_type(string input, string opcode){
    string Binary = hexToBinary(input[0]) + hexToBinary(input[1]) + hexToBinary(input[2]) + hexToBinary(input[3]) + hexToBinary(input[4]) + hexToBinary(input[5]) + hexToBinary(input[6]) + hexToBinary(input[7]);
    string rd = Binary.substr(20,5);
    string imm = input.substr(0,1) + input.substr(1,1) + input.substr(2,1) + input.substr(3,1) + input.substr(4,1) ;  
    if(opcode == "0110111"){
        cout << "lui " ;
    }
    else if(opcode == "0010111"){
        cout << "auipc " ;
    }
    cout << "x" << binaryToDecimal(rd) << ", " << "0x" << imm << endl;
}
string B_type(string input){
    string Binary = hexToBinary(input[0]) + hexToBinary(input[1]) + hexToBinary(input[2]) + hexToBinary(input[3]) + hexToBinary(input[4]) + hexToBinary(input[5]) + hexToBinary(input[6]) + hexToBinary(input[7]);
    string imm1 = Binary.substr(20,5);
    string funct3 = Binary.substr(17,3);
    string rs1 = Binary.substr(12,5);
    string rs2 = Binary.substr(7,5);
    string imm2 = Binary.substr(0,7);
    string imm = imm2.substr(0,1) + imm1.substr(4,1) + imm2.substr(1,6) + imm1.substr(0,4) + "0" ;

    //specifying the name of the function to jump to
    string jumpFunc = "L1" ;

        if (funct3 == "000")
        {
            cout << "beq " ;
        }
        else if (funct3 == "001")
        {
            cout << "bne " ;
        }
        else if (funct3 == "100")
        {
            cout << "blt " ;
        }
        else if (funct3 == "101")
        {
            cout << "bge " ;
        }
        else if (funct3 == "110")
        {
            cout << "bltu " ;
        }
        else if (funct3 == "111")
        {
            cout << "bgeu " ;
        }

        cout << "x" << binaryToDecimal(rs1) << ", x" <<  binaryToDecimal(rs2) << ", " << jumpFunc <<endl;

        //Same as in J type function- creating a string to store both the immediate value and the name of the function to jump to
        string returnValue = imm + jumpFunc;
        return returnValue ;
}
void S_type(string input){
    string Binary = hexToBinary(input[0]) + hexToBinary(input[1]) + hexToBinary(input[2]) + hexToBinary(input[3]) + hexToBinary(input[4]) + hexToBinary(input[5]) + hexToBinary(input[6]) + hexToBinary(input[7]);
    string funct3 = Binary.substr(17,3);
    string imm1 = Binary.substr(20,5);
    string rs1 = Binary.substr(12,5);
    string rs2 = Binary.substr(7,5);
    string imm2 = Binary.substr(0,7);
    string imm = imm2 + imm1 ;
    //cout << imm <<endl;
        if (funct3 == "000")
        {
            cout << "sb " ;
        }
        else if (funct3 == "001")
        {
            cout << "sh " ;
        }
        else if (funct3 == "010")
        {
            cout << "sw " ;
        }
        else if (funct3 == "011")
        {
            cout << "sd " ;
        }
    cout << "x" << binaryToDecimal(rs2) << ", " <<   twosComplementToDecimal(imm) << "(" << "x" << binaryToDecimal(rs1) << ")" << endl;
}
void I_type(string input, string opcode){
    string Binary = hexToBinary(input[0]) + hexToBinary(input[1]) + hexToBinary(input[2]) + hexToBinary(input[3]) + hexToBinary(input[4]) + hexToBinary(input[5]) + hexToBinary(input[6]) + hexToBinary(input[7]);
    string funct3 = Binary.substr(17,3);
    string rd = Binary.substr(20,5);
    string rs1 = Binary.substr(12,5);
    string imm = hexToBinary(input[0]) + hexToBinary(input[1]) + hexToBinary(input[2]);  
    string rs2 = Binary.substr(7,5);
    //Imm[6:11] for slli, srli, srai 
    string funct6 = imm.substr(0,6);
    reverse(funct6.begin(),funct6.end());
    // cout << imm << endl;
        //Type-1
        if(funct3 == "000" && opcode == "0010011"){
            cout << "addi " ;
        }
        else if (funct3 == "100" && opcode == "0010011")
        {
            cout << "xori " ;
        }
        else if (funct3 == "110" && opcode == "0010011")
        {
            cout << "ori " ;
        }
        else if (funct3 == "111" && opcode == "0010011")
        {
            cout << "andi " ;
        }
        else if (funct3 == "001" && funct6 == "000000" && opcode == "0010011")
        {   
            imm = imm.substr(7,5) ;
            cout << "slli " ;
        }
        else if (funct3 == "101" && funct6 == "000000" && opcode == "0010011")
        {
            imm = imm.substr(7,5) ;
            cout << "srli " ;
        }
        else if (funct3 == "101" && funct6 == "000010" && opcode == "0010011")
        {
            imm = imm.substr(7,5) ;
            cout << "srai " ;
        }
        else if (funct3 == "010" && opcode == "0010011")
        {
            cout << "slti " ;
        }
        else if (funct3 == "011" && opcode == "0010011")
        {
            cout << "sltiu " ;
        }
        //Type-2
        else if (funct3 == "000" && opcode == "0000011")
        {
            cout << "lb " ;
        }
        else if (funct3 == "001" && opcode == "0000011")
        {
            cout << "lh " ;
        }
        else if (funct3 == "010" && opcode == "0000011")
        {
            cout << "lw " ;
        }
        else if (funct3 == "011" && opcode == "0000011")
        {
            cout << "ld " ;
        }
        else if (funct3 == "100" && opcode == "0000011")
        {
            cout << "lbu " ;
        }
        else if (funct3 == "101" && opcode == "0000011")
        {
            cout << "lhu " ;
        }
        else if (funct3 == "110" && opcode == "0000011")
        {
            cout << "lwu " ;
        }
        //Type-3
        else if (funct3 == "000" && opcode == "1100111")
        {
            cout << "jalr " ;
        }
        //Type-4
        else if (funct3 == "000" && imm == "000000000000" && opcode == "1110011")
        {
            cout << "ecall " ;
        }
        else if (funct3 == "000" && imm == "000000000001" && opcode == "1110011")
        {
            cout << "ebreak " ;
        }
    //cout << imm <<endl;
    if(opcode != "0000011"){
    cout << "x" << binaryToDecimal(rd) << ", " << "x" << binaryToDecimal(rs1) << ", " << twosComplementToDecimal(imm) <<endl;
    }
    else{
        cout << "x" << binaryToDecimal(rd) << ", " << twosComplementToDecimal(imm) << "(" << "x" << binaryToDecimal(rs1) << ")"  <<endl;
    }
}
void R_type(string input){
    string Binary = hexToBinary(input[0]) + hexToBinary(input[1]) + hexToBinary(input[2]) + hexToBinary(input[3]) + hexToBinary(input[4]) + hexToBinary(input[5]) + hexToBinary(input[6]) + hexToBinary(input[7]);
    string funct3 = Binary.substr(17,3);
    string funct7 = Binary.substr(0,7);
    string rd = Binary.substr(20,5);
    string rs1 = Binary.substr(12,5);
    string rs2 = Binary.substr(7,5);
    for (int i = 0; i < 10; i++)
    {
        if(funct3 == "000" && funct7 == "0000000"){
            cout << "add " ;
            break;
        }
        else if (funct3 == "000" && funct7 == "0100000")
        {
            cout << "sub " ;
            break;
        }
        else if (funct3 == "100" && funct7 == "0000000")
        {
            cout << "xor " ;
            break;
        }
        else if (funct3 == "110" && funct7 == "0000000")
        {
            cout << "or " ;
            break;
        }
        else if (funct3 == "111" && funct7 == "0000000")
        {
            cout << "and " ;
            break;
        }
        else if (funct3 == "001" && funct7 == "0000000")
        {
            cout << "sll " ;
            break;
        }
        else if (funct3 == "101" && funct7 == "0000000")
        {
            cout << "srl " ;
            break;
        }
        else if (funct3 == "101" && funct7 == "0100000")
        {
            cout << "sra " ;
            break;
        }
        else if (funct3 == "010" && funct7 == "0000000")
        {
            cout << "slt " ;
            break;
        }
        else if (funct3 == "011" && funct7 == "0000000")
        {
            cout << "sltu " ;
            break;
        }
    }

    cout << "x" << binaryToDecimal(rd) << ", " << "x" << binaryToDecimal(rs1) << ", " <<  "x" << binaryToDecimal(rs2) <<endl;    
}
int main(){

    string input[] = {
       "007201b3",
        "00720863",
        "00c0006f",
        "00533623",
        "100004b7",
        "00c50493"       
        };
    int size_inputArray = sizeof(input)/32 ;
    
    string opcode[] = {
        "0110011" , //#R
        "0010011" , //#I
        "0000011" , //#I
        "0100011" , //#S
        "1100011" , //#B
        "1101111" , //#J
        "1100111" , //#I
        "0110111" , //#U
        "0010111" , //#U
        "1110011"   //#I
    };
    int type = 0 ;

    // Setting the offset to -1 because I am printing the function name when offset = 0 
    int offset_B[20] = {0};
    int offset_J[20] = {0};

    for (int i = 0; i < 20; i++)
    {
        offset_B[i] = offset_J[i] = -1;
    }
    

    //Creating string variables to get the function to jump to for B/J type
    string jumpB ;
    string jumpJ ; 
    string temp ;

    //running a loop through all the input hex's
    for (int i = 0; i < size_inputArray; i++)
    {   
        //getting the last two hex digits(7th and 8th) coz they contain 8 bits in total and deriving the opcode from last 7 of 8 bits 
        string Hex_7_8 = hexToBinary(input[i][6]) + hexToBinary(input[i][7]);
        for (int j = 0; j < 10; j++)
        {
            if(Hex_7_8.substr(1,7) == opcode[j]){
                type = j ;
            }
        }
        switch (type)
        {
        case 0:
            R_type(input[i]);
            break;
        case 1:
            I_type(input[i],opcode[type]);
            break;
        case 2:
            I_type(input[i],opcode[type]);
            break;
        case 3:
            S_type(input[i]);
            break;
        case 4:
            //storing the returned value in temp string
            //getting the offset(number of lines to skip) in offset_B by breaking down the string i returned from the function into 2 substrings
            //getting the name of the function in jumpB

            //Here I can take the name of the jump Function and then send it as an input to the function for the particular name of Jump function.
            //By default I am taking the name of the jump Function to be "L1"
            temp = B_type(input[i]);
            offset_B[i] = twosComplementToDecimal(temp.substr(0,13))/4;
            jumpB = temp.substr(13,(temp.length() - 13)) ;
            break;
        case 5:

            //same as case 4
            
            //Here also, I can take the name of the jump Function and then send it as an input to the function for the particular name of Jump function.
            //Here also, By default I am taking the name of the jump Function to be "L1"

            temp = J_type(input[i]);
            offset_J[i] = twosComplementToDecimal(temp.substr(0,20))/2 ;
            jumpJ = temp.substr(20,(temp.length() - 20)) ;
            break;
        case 6:
            I_type(input[i],opcode[type]);
            break;
        case 7:
            U_type(input[i],opcode[type]);
            break;
        case 8:
            U_type(input[i],opcode[type]);
            break;
        case 9:
            I_type(input[i],opcode[type]);
            break;
        default:
            break;
        }
        // cout << offset_B << " " << offset_J << endl;
    
        for (int k = 0; k < 20; k++)
        {
            for (int l = 0; l < 20; l++){
                if(offset_B[k] == offset_J[l]){
                    offset_J[l] = -1;
                }
            }
        }

        for (int k = 0; k < 20; k++)
        {
            offset_B[k] = offset_B[k] - 1 ;
            offset_J[k] = offset_J[k] - 1 ;
            
            if(offset_B[k] == 0){
                cout << jumpB << " : " ;
            }
            if(offset_J[k] == 0){
                cout << jumpJ << " : " ;
            }
        }
    }    
}
