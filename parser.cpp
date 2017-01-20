#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char* argv[]) {

ifstream in;

in.open(argv[1]);	
	
if (argc < 2 || argc > 2 ) {
	
	cerr << "Error :INVALID ARGUMENTS"<<endl;
	return -1;
	
}	

if (!in) {
	cerr << "Error :FILE NOT FOUND";
	return -1;
	
}

int line_count = 1;	
	
int numberOfComments = 0;	
int numberOfCommands = 0;
int numberOfALU = 0;
int numberOfLd_Sd = 0;
int numberOfCompare_Jump	= 0;
	
while(in)	{

int sizeOfOpr = 0;	
char current_line[100];
char current_Operand[100];
 current_Operand[0] = -1;
char modified_current_line[100];
int code_for_registor_combo = 0;
int code_for_operand;
int first_space = 0;
int j = 0;
char first = '0';
char second = '0';
char third = '0';
char first1[100];
char second1[100];
char third1[100];
int is_there_a_third_operand = -1;
is_there_a_third_operand = -1;

// /* RN , RN - 1                                SUB - 1, Subi - 2                       if there is a third one - 1, else -1
   // NNNN, RN - 2                               ADD = 3, ADDi - 4 
   // RN, NNNN - 3                               MUL - 5 , MULi - 6
   // RN, RN, RN - 4                             DIV - 7, DIVi - 8
  // RN, NNNN, RN - 5                            JMP - 9 , JZ - 10
  // NNNN - 6                                     JNZ - 11 , JGZ - 12
  // ERROR - -1                                    JGEZ - 13, JLZ - 14
 //                                               JLEZ - 15 , ERROR - -1
 // */                                              SD - 16, LD - 17
 //                                                 SDi = 18  LDi - 19

in.getline(current_line, 100);
if (current_line[0] != '\0') {	
cout << current_line<<endl;

for (int i = 0; i < 100 ; i++) {
	if (current_line[i] == '#') {
		numberOfComments = numberOfComments + 1;
		break;
	}
	
}

int k = 0;
while (current_line[k] == ' ' || current_line[k] == '\t') {k++;}
	





if (current_line[k+2] == ' ' ||current_line[k+2] == '\t' ) {
	sizeOfOpr = 2;
}

else if (current_line[k+3] == ' '||current_line[k+3] == '\t') {
	sizeOfOpr = 3;
}

else if (current_line[k+4] == ' '||current_line[k+4] == '\t') {
	sizeOfOpr = 4;
}



int ba  = k;
int sa = 0;
for ( k = k ; k < ba + sizeOfOpr ; k++ ){

	
	current_Operand[sa] = current_line[k];
	sa++;
	
	
	
	}	

	
current_Operand[k-ba] = '\0';



switch (current_Operand[0]) {
	

	
case 'S' :	
if(current_Operand[1] == 'U' && current_Operand[2] == 'B' && current_Operand[3] != 'i') {
	code_for_operand = 1;
break;
	}

else if(current_Operand[1] == 'U' && current_Operand[2] == 'B' && current_Operand[3] == 'i')  {
	code_for_operand = 2;
break;
	}
else if (current_Operand[1] == 'D' ) {
	code_for_operand = 16;
	break;
}

else if (current_Operand[1] == 'D' && current_Operand[2] == 'i' ) {
	code_for_operand = 18;
	break;
}

else {
 code_for_operand = -1;
	break;
}

	
case 'L' :
if (current_Operand[1] == 'D' && current_Operand[2] != 'i' ) {
	code_for_operand = 17;
	break;
}

if (current_Operand[1] == 'D' && current_Operand[2] == 'i' ) {
	code_for_operand = 19;
	break;
}


else {
 code_for_operand = -1;
	break;
}


case 'A' : 
if(current_Operand[1] == 'D' && current_Operand[2] == 'D' && current_Operand[3] != 'i') {
	code_for_operand = 3;
	break;
	
}

else if(current_Operand[1] == 'D' && current_Operand[2] == 'D' && current_Operand[3] == 'i') {
	
	code_for_operand = 4;
	break;
}

else {
 code_for_operand = -1;
	break;
}

 	
case 'D' :

if(current_Operand[1] == 'I' && current_Operand[2] == 'V' && current_Operand[3] != 'i') {
	code_for_operand = 7;
	break;
	
}


else if(current_Operand[1] == 'I' && current_Operand[2] == 'V' && current_Operand[3] == 'i') {
	code_for_operand = 8;
	break;
	
}
else {
 code_for_operand = -1;
	break;
}


case 'M' :

if(current_Operand[1] == 'U' && current_Operand[2] == 'L' && current_Operand[3] != 'i') {
	code_for_operand = 5;
	break;
	
}


else if(current_Operand[1] == 'U' && current_Operand[2] == 'L' && current_Operand[3] == 'i') {
	code_for_operand = 6;
	break;
	
}

else {
 code_for_operand = -1;
	break;
}


case 'J' :	


if (current_Operand[1] == 'M' && current_Operand[2] == 'P') {
	
	code_for_operand = 9;
	break;
}

else if (current_Operand[1] == 'G' && current_Operand[2] == 'E' && current_Operand[3] == 'Z') {
	
	code_for_operand = 13;
	break;
}

else if (current_Operand[1] == 'N' && current_Operand[2] == 'Z' ) {
	
	code_for_operand = 11;
	break;
}

else if (current_Operand[1] == 'Z'  ) {
	
	code_for_operand = 10;
	break;
}


else if (current_Operand[1] == 'L' && current_Operand[2] == 'Z' ) {
	
	code_for_operand = 14;
	break;
}

else if (current_Operand[1] == 'G' && current_Operand[2] == 'Z' ) {
	
	code_for_operand = 12;
	break;
}


else if (current_Operand[1] == 'L' && current_Operand[2] == 'E' && current_Operand[3] == 'Z') {
	
	code_for_operand = 15;
	break;
}


else {
	code_for_operand = -1;
	break;
}

default :

code_for_operand = -1;
break;		

}	





if (code_for_operand == 9) {
	


while (current_line[k] == ' '){k++;}	
	


int g = 0;



int jack = k;
while (current_line[k] != ' ' && current_line[k] != '\0' ) {
	first1[g] = current_line[k];
	g++;
	k++;
	
	
}	
	
	
first1[k-jack] = '\0';	
	
	
	
	
}

else if (code_for_operand != -1) {
for ( j = k ; current_line[j] == ' ' ; j++) {}
for ( j = j ; current_line[j] == '\t' ; j++) {}
int l = 0;
k = j;
while(current_line[j] != ' ') {
	if (current_line[j] != ','){
	first1[l] = current_line[j];
	j++;
	l++;	}
	
	else break;
}	
first1[4] = '\0';
if (j - k < 4) {	
	first1[2] = '\0';
}




for ( j = j; current_line[j] == ' ' ; j++) {}
l = 0;
for ( j = j ; current_line[j] == ',' ; j++) {}	

for ( j = j; current_line[j] == ' ' ; j++) {}




l = 0;
k = j;



while(current_line[j] != ' ' && current_line[j] != ',' && current_line[j] != '\0') {
	
	second1[l] = current_line[j];
	j++;
	l++;	

}
second1[4] = '\0';
if (j - k < 4) {	
	second1[2] = '\0';
}



if (current_line[j] == ',') {
	is_there_a_third_operand = 1;
}





for(int i = j ; i < 100 ; i ++) {
	if (current_line[i] == ',') {
	j = i;
	is_there_a_third_operand = 1;
	break;
		
	}
	
	
}


if (is_there_a_third_operand == 1) {
for (j = j + 1; current_line[j] == ' ' ; j++) {}
first_space = j;	
l = 0;	
while(current_line[j] != '\0') {
	if (current_line[j] != ' '){
	third1[l] = current_line[j];
	j++;
	l++;	
	}
	else {break;}

	}		
third1[4] = '\0';
if (j - first_space < 4) {
third1[2] = '\0';}}
}



if (code_for_operand == -1) {
	
	cerr << "Error in: " << line_count << " Inalid Operand" << endl;
}

if (first1[0] == 'R' && first1 [2] == '\0' ) {
	first = 'R';
}

else if (first1[0] != 'R' && first1[1] != ' ' && first1[2] != ' ' && first1[3] != ' ' ) {
	first = 'N';
	
}

else {
	
	first = '1';
}


if (second1[0] == 'R' && second1 [2] == '\0') {
	second = 'R';
}

else if (second1[0] != 'R' && second1[1] != ' ' && second1[2] != ' ' && second1[3] != ' ' ) {
	second = 'N';
	
}

else {
	
	second = '1';
}


if (is_there_a_third_operand == 1){
if (third1[0] == 'R' && third1 [2] == '\0' ) {
	third = 'R';
}

else if (third1[0] != 'R' && third1[1] != ' ' && third1[2] != ' ' && third1[3] != ' ' ) {
	third = 'N';
	
}

else {
	
	third = '2';
}
}



if (first == '1' || second == '1' || third == '2') {
	cerr << "Error in Line " << line_count << " Invalid OPCODE" << endl;
	
}

if (code_for_operand == 9) {
	second = '0';
	third = '0';
	
}



if (first == 'R' && second == 'R' && third == '0'){code_for_registor_combo=1;}
else if (first == 'N' && second == 'R' && third == '0'){code_for_registor_combo=2;}
else if (first == 'R' && second == 'N' && third == '0'){code_for_registor_combo=3;}
else if (first == 'R' && second == 'R' && third == 'R'){code_for_registor_combo=4;}
else if (first == 'R' && second == 'N' && third == 'R'){code_for_registor_combo=5;}
else if (first == 'N' && second == '0' && third == '0'){code_for_registor_combo=6;}
else  if (first == 'N' && second == 'N' && third == '0'){code_for_registor_combo=7;}	

switch (code_for_operand) {
	
case 1 : if (code_for_registor_combo == 4) {numberOfCommands++;
numberOfALU++;
break;}		
case 2 : if (code_for_registor_combo == 5) {numberOfCommands++;
numberOfALU++;
break;}	
case 3 : if (code_for_registor_combo == 4) {numberOfCommands++;
numberOfALU++;
break;}
case 4 : if (code_for_registor_combo == 5) {numberOfCommands++;
numberOfALU++;
break;}	
case 5 : if (code_for_registor_combo == 4) {numberOfCommands++;
numberOfALU++;
break;}		
case 6 : if (code_for_registor_combo == 5) {numberOfCommands++;
numberOfALU++;
break;}	
case 7 : if (code_for_registor_combo == 4) {numberOfCommands++;
numberOfALU++;
break;}		
case 8 : if (code_for_registor_combo == 5) {numberOfCommands++;
numberOfALU++;
break;}	
case 9 : if (code_for_registor_combo == 6) {numberOfCommands++;
numberOfCompare_Jump++;
break;}	
case 10: if (code_for_registor_combo == 3) {numberOfCommands++;
numberOfCompare_Jump++;
break;}	
case 11: if (code_for_registor_combo == 3) {numberOfCommands++;
numberOfCompare_Jump++;
break;}	
case 12: if (code_for_registor_combo == 3) {numberOfCommands++;
numberOfCompare_Jump++;
break;}	
case 13: if (code_for_registor_combo == 3) {numberOfCommands++;
numberOfCompare_Jump++;
break;}	
case 14: if (code_for_registor_combo == 3) {numberOfCommands++;
numberOfCompare_Jump++;
break;}	
case 15: if (code_for_registor_combo == 3) {numberOfCommands++;
numberOfCompare_Jump++;
break;}	
case 16: if (code_for_registor_combo == 1 || code_for_registor_combo == 2) {numberOfCommands++;
numberOfLd_Sd++;
break;}	
case 17: if (code_for_registor_combo == 1 || code_for_registor_combo == 3) {numberOfCommands++;
numberOfLd_Sd++;
break;}		
case 18:  if (code_for_registor_combo == 7 || code_for_registor_combo == 2) {numberOfCommands++;
numberOfLd_Sd++;
break;}	
case 19:  if (code_for_registor_combo == 2) {numberOfCommands++;
numberOfLd_Sd++;
break;}		
default : cerr << "Error in line " << line_count<<": Invalid Operand, Opcode Combination" << endl;

	
}



	line_count++;
	
}	

	}


cout << "Total number of assembly instructions: " << numberOfCommands<<endl;
cout << "Number of Load/Store: " << numberOfLd_Sd << endl;
cout << "Number of ALU: " << numberOfALU << endl;
cout << "Number of Compare/Jump: "<<numberOfCompare_Jump << endl;
return 0;	
}




