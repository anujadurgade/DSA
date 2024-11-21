#include <iostream>
#include <stack>
using namespace std;
class InToPost
 {
 char input[50];
 stack <char> st;// st is stack of characters
public:
 InToPost();
 bool isOpertator(char ch);
 int getISP();
 int getICP(char ch);
 void convert();
 };
void InToPost::convert()
 {
 int k=0,icp,isp;
 char temp;
 while(input[k] !='\0')// do for all input token
 {
 if(isOpertator(input[k]))
 {// input is operator
 if(input[k]=='(')
 {// input is opening bracket
 st.push(input[k]);
 k++;//go to next input or advance
 }
 else// input is not '(' bracket
 {
 if(input[k]== ')')
 {// pop and display till opening bracket
 do
 {
 temp = st.top();
 if(temp != '(')
 {
 cout<<temp;
 }
 st.pop();
 }while(temp != '(');
 k++;//go to next input or advance
 }
 else// input is not '(' or ')' bracket
 {
 icp = getICP(input[k]);
 isp = getISP();
 if(icp > isp)
 {// if icp > isp
 st.push(input[k]);
 k++;//go to next input or advance
 }
 else
 {// if icp < = isp
 cout<<st.top();// pop and out put
 st.pop();// remove it from stack
 }
 }
 }
 }
 else
 {// input is operand
 cout<<input[k];
 k++;//go to next input or advance
 }
 }
 //pop and display all operators on stack
 while(!st.empty())
 {
 cout<<st.top();
 st.pop();
 }
 }
InToPost::InToPost()
 {
 cout<<"\n Enter the infix expression";
 cin>>input;
 }
//This function returns true if input ch is operator else it returns false
bool InToPost::isOpertator(char ch)
 {
 if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='('||ch==')')
 return true;
 else
 return false;
 }
int InToPost::getISP()
 {
 char ch;
 if(!st.empty())
 {
 ch = st.top();
 if(ch == '+'|| ch == '-')
 return 1;
 if(ch == '*'|| ch == '/')
return 2;
 if(ch == '^')
 return 3;
 if(ch == '(')
 return 0;
 if(ch == ')')
 return -1;
 }
 return 0;
 }
int InToPost::getICP(char ch)
 {
 if(ch == '+'|| ch == '-')
 return 1;
 if(ch == '*'|| ch == '/')
 return 2;
 if(ch == '^')
 return 4;
 if(ch == '(')
 return 5;
 if(ch == ')')
 return -1;
 return 0;
 }
int main()
 {
 InToPost ip;
 cout<<"\n The postfix expression is \n";
 ip.convert();
 return 0;
 }