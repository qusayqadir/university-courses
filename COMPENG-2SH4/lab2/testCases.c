#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "Questions.h"
    

    
    
//=========Question 1==================================
void TestQ1_add(CuTest *tc) {

	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double input2[5] = {1.50, 2.00, 3.30, 9.90, 1.00};
	double actual[5];
	double expected [5] = {5.10, 6.78, 9.30, 19.90, 1.01};
 	add_vectors(input1,input2,actual,n);
	


	int i;
	for (i=0; i<n; i++)
		CuAssertDblEquals(tc, expected[i], actual[i],0.009);



}

void TestQ1_add_2(CuTest *tc) {


	//new test case
	int k = 3; 
	double input3[3] = { 1.20, 1.50, 1.70}; 
	double input4[3] = { 2.45, 1.75, 1.80};
	double actual2[3]; 
	double expected2 [3] = { 3.65, 3.25, 3.50 }; 
	add_vectors(input3, input4, actual2, k );
	int j;
	for (j=0; j<k; j++)
		CuAssertDblEquals(tc, expected2[j], actual2[j],0.009);


}



    
void TestQ1_scalar_prod(CuTest *tc) {

	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double input2[5] = {1.50, 2.00, 3.30, 9.90, 1.00};
	double expected=133.770 ;
	double actual = scalar_prod(input1,input2,n);

	CuAssertDblEquals(tc, expected, actual,0.009);

}

    
void TestQ1_scalar_prod_2(CuTest *tc) {

	//new test case
	int k = 3;
	double input3[3] = {1.50, 2.10, 5.10};
	double input4[3] = {1.50, .50, .75};
	double expected2= 7.125;
	double actual2 = scalar_prod(input3,input4,k);

	CuAssertDblEquals(tc, expected2, actual2, 0.009);

}

void TestQ1_norm(CuTest *tc) {

	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double expected=13.108 ;
    double actual = norm2(input1,n);

    CuAssertDblEquals(tc, expected, actual,0.009);

}

void TestQ1_norm_2(CuTest *tc) {


	//new test case
	int k = 2;
	double input2[2] = {4.78, 6.01};
	double expected2= 7.67909;
    double actual2 = norm2(input2,k);

    CuAssertDblEquals(tc, expected2, actual2,0.009);
}

//===========================================================
//=================Question 2================================  

void TestQ2(CuTest *tc) {
	int n = 3;
	int input[3][3] = {{1, 2, 3},{ 5, 8, 9},{ 0, 3, 5}};
	int expected[9]= {1, 2, 5, 3, 8, 0, 9, 3, 5};
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}

void TestQ2_1(CuTest *tc) {

	int k = 3;
	int input2[3][3] = {{1, 2, 3},{ 4, 5, 6},{ 7, 8, 9}};
	int expected2[9]= {1, 2, 4, 3, 5, 7, 6, 8, 9};
	int actual2[9];
	diag_scan(input2,actual2);

	int j;
	for (j=0; j<k*k; j++)
		CuAssertIntEquals(tc, expected2[j], actual2[j]);


}
void TestQ2_2(CuTest *tc){
	int f =3;
	int input3[3][3] = {{4, 5, 10},{ 4, 8, 9}, {0,0,0}};
	int expected3[9]= {4,5,4,10,8,0,9,0,0};
	int actual3[9];
	diag_scan(input3,actual3);

	int w;
	for (w=0; w<f*f; w++)
		CuAssertIntEquals(tc, expected3[w], actual3[w]);


}

void TestQ2_3(CuTest *tc){
	int r=3;
	int input4[3][3] = {{4, 5, 10},{ 4, 8, 9}, {0,0,0}};
	int expected4[9]= {4,5,4,10,8,0,9,0,0};
	int actual4[9];
	diag_scan(input4,actual4);

	int c;
	for (c=0; c<r*r; c++)
		CuAssertIntEquals(tc, expected4[c], actual4[c]);


}

 
    
//===========================================================
//=================Question 3================================   

void TestQ3_1(CuTest *tc) {
	int n=8;
	int input[]={0,0,23,0,-7,0,0,48};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {{23, 2}, {-7, 4}, {48, 7}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}


void TestQ3_2(CuTest *tc) {
	int n=5;
	int input[]={0,7,0,-1,88};
	struct Q3Struct actual[5] = {0};
	struct Q3Struct expected[5] = {{7, 1}, {-1, 3}, {88, 4}, {0, 0}, {0, 0}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}


void TestQ3_3(CuTest *tc) {
	int n=2;
	int input[]={2, 3};
	struct Q3Struct actual[2] = {0};
	struct Q3Struct expected[2] = {{2, 0}, {3, 1}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}


void TestQ3_4(CuTest *tc) {
	int n=5;
	int input[]={0,5,0,0,12};
	struct Q3Struct actual[5] = {0};
	struct Q3Struct expected[5] = {{5, 1}, {12, 4}, {0, 0}, {0, 0}, {0, 0}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

void TestQ3_zeros(CuTest *tc) {
	int n=8;
	int input[]={0,0,0,0,0,0,0,0};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {0};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

void TestQ3_combined(CuTest *tc) {
	int n=8;
	int input[]={0,0,23,0,-7,0,0,48};
	struct Q3Struct int_result[8] = {0};
	int expected[8] = {0,0,23,0,-7,0,0,48};
	int actual[8] = {0};
	efficient(input,int_result,n);
	reconstruct(actual, 8, int_result, 3);

	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i], actual[i]);
	}
}

void TestQ3_combined_2(CuTest *tc) {
	int n=5;
	int input[]={0,7,0,-1,88};
	struct Q3Struct int_result[5] = {0};
	int expected[5] ={0,7,0,-1,88};
	int actual[5] = {0};
	efficient(input,int_result,n);
	reconstruct(actual, 5, int_result, 3);

	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i], actual[i]);
	}
}
void TestQ3_combined_3(CuTest *tc) {
	int n=2;
	int input[]={2, 3};
	struct Q3Struct int_result[2] = {0};
	int expected[2] = {2,3};
	int actual[2] = {0};
	efficient(input,int_result,n);
	reconstruct(actual, 2, int_result, 2);

	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i], actual[i]);
	}
}

void TestQ3_combined_4(CuTest *tc) {
	int n=5;
	int input[]={0,5,0,0,12};
	struct Q3Struct int_result[5] = {0};
	int expected[5] = {0,5,0,0,12};
	int actual[5] = {0};
	efficient(input,int_result,n);
	reconstruct(actual, 5, int_result, 2);

	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i], actual[i]);
	}
}

//===========================================================
//=================Question 4================================   
void TestQ4_BubbleSort_1(CuTest *tc) 
{
	int n=6;
	struct Q4Struct input[]={{10, 'c'}, {2, 'B'}, {-5, 'k'}, {12, 'z'}, {77, 'a'}, {-42, '?'}};	
	struct Q4Struct expected[]={{-42, '?'}, {-5, 'k'}, {2, 'B'}, {10, 'c'}, {12, 'z'}, {77, 'a'}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_BubbleSort_2(CuTest *tc) 
{
	int n=8;
	struct Q4Struct input[]={{-23, '='}, {78, ' '}, {11, 'Y'}, {-2, '0'}, {41, '+'}, {0, 'm'}, {55, 'T'}, {-9, 'o'}};	
	struct Q4Struct expected[]={{-23, '='}, {-9, 'o'}, {-2, '0'}, {0, 'm'}, {11, 'Y'}, {41, '+'}, {55, 'T'}, {78, ' '}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}


void TestQ4_SelectionSort_1(CuTest *tc) 
{
	int n=6;
	struct Q4Struct input[]={{10, 'c'}, {2, 'B'}, {-5, 'k'}, {12, 'z'}, {77, 'a'}, {-42, '?'}};	
	struct Q4Struct expected[]={{-42, '?'}, {-5, 'k'}, {2, 'B'}, {10, 'c'}, {12, 'z'}, {77, 'a'}};		
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_SelectionSort_2(CuTest *tc) 
{
	int n=8;
	struct Q4Struct input[]={{-23, '='}, {78, ' '}, {11, 'Y'}, {-2, '0'}, {41, '+'}, {0, 'm'}, {55, 'T'}, {-9, 'o'}};	
	struct Q4Struct expected[]={{-23, '='}, {-9, 'o'}, {-2, '0'}, {0, 'm'}, {11, 'Y'}, {41, '+'}, {55, 'T'}, {78, ' '}};			
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_SelectionSort_3(CuTest *tc) 
{
	int n=5;
	struct Q4Struct input[]={{11, 'l'}, {51, 'r'}, {-1, '!'}, {-25, '0'}, {100, 'q'}};	
	struct Q4Struct expected[]={{-25, '0'}, {-1, '!'}, {11, 'l'}, {51, 'r'}, {100, 'q'}};	
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_SelectionSort_4(CuTest *tc) 
{
	int n=3;
	struct Q4Struct input[]={{2, 'q'}, {5, 'w'}, {-1, 'e'}};	
	struct Q4Struct expected[]={{-1,'e'},{2,'q'},{5,'w'}};	
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_SelectionSort_5(CuTest *tc) 
{
	int n=5;
	struct Q4Struct input[]={{101, 'f'}, {1, 'h'}, {-1, '@'}, {-52, '?'}, {0, 'l'}};	
	struct Q4Struct expected[]={{-52, '?'}, {-1, '@'}, {0, 'l'}, {1, 'h'}, {101, 'f'}};	
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}




CuSuite* Lab2GetSuite() {

	CuSuite* suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestQ1_add);
	SUITE_ADD_TEST(suite, TestQ1_add_2);
	SUITE_ADD_TEST(suite, TestQ1_scalar_prod);
	SUITE_ADD_TEST(suite, TestQ1_scalar_prod_2);
	SUITE_ADD_TEST(suite, TestQ1_norm);
	SUITE_ADD_TEST(suite, TestQ1_norm_2);

	SUITE_ADD_TEST(suite, TestQ2);
	SUITE_ADD_TEST(suite, TestQ2_1);
	SUITE_ADD_TEST(suite, TestQ2_2);
	SUITE_ADD_TEST(suite, TestQ2_3);

	SUITE_ADD_TEST(suite, TestQ3_1);
	SUITE_ADD_TEST(suite, TestQ3_2);
	SUITE_ADD_TEST(suite, TestQ3_3);
	SUITE_ADD_TEST(suite, TestQ3_4);
	SUITE_ADD_TEST(suite, TestQ3_zeros);
	SUITE_ADD_TEST(suite, TestQ3_combined);
	SUITE_ADD_TEST(suite, TestQ3_combined_2);
	SUITE_ADD_TEST(suite, TestQ3_combined_3);
	SUITE_ADD_TEST(suite, TestQ3_combined_4);

	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_1);
	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_2);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_1);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_2);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_3);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_4);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_5);


	return suite;
}
    
