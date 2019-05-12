#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <curses.h>
#include <stdlib.h>
using namespace std;

//存储登录用户名
class login{
    public:
        map<string,string>user;
        map<string,string>::iterator iterUser;
        int userNum=10;//允许注册的最大用户数，修改可改变阈值。
        int contentNum=10;//允许存储的内容，修改可改变阈值。
};

int main(){
    
    login log;
    int exit=0;
    
    /*
    ofstream write1;write1.open("/Users/shiyi/Desktop/robot/user.txt",ios::out);
    if(!write1.is_open())exit(0);
    write1.close();

    ifstream read1;read1.open("/Users/shiyi/Desktop/robot/user.txt");
    if(!read1.is_open())exit(0);
    read1.close();
    */

    ifstream read1;
    ofstream write1;
    int flag;

    A:while(!exit){
        string userName[log.userNum];string name;string signup_name;
        string userPass[log.userNum];string pass;string signup_pass;string signup_pass1;
        
        //菜单区域
        cout<<"╪╪╪╪╪╪╧╧╧╧╧╧╧╧╪╪╪╪╪╪"<<endl;
        cout<<"1    注册"<<endl;
        cout<<"2    登录"<<endl;
        cout<<"╪╪╪╪╪╪╧╧╧╧╧╧╧╧╪╪╪╪╪╪"<<endl;
        int num;cin>>num;
        
        switch (num)
        {
        case 1:
            cout<<"感谢注册！"<<endl;
            cout<<"用户名：";cin>>signup_name;
            cout<<"密码：";cin>>signup_pass;
            cout<<"再一次输入密码，以确认：";cin>>signup_pass1;
            if(signup_pass==signup_pass1){
                system("clear");
                cout<<"注册成功！"<<endl;
                write1.open("/Users/shiyi/Desktop/robot/user.txt",ios::app);
                write1<<endl<<signup_name;
                write1<<endl<<signup_pass;
                write1.close();
            }else{
                cout<<"两次密码不一样！！！"<<endl;
            }
            
            break;
        case 2:
            flag=0;//验证成功
            cout<<"用户名：";cin>>name;
            cout<<"密码：";cin>>pass;
            
            read1.open("/Users/shiyi/Desktop/robot/user.txt");
            
            for(int i=0;i<log.userNum*2;i++){
                read1>>userName[i];
                read1>>userPass[i+1];
                i+=1;
            }
            read1.close();

            for(int i=0;i<log.userNum*2;i++){
                if(userName[i]==name){
                    if(userPass[i+1]==pass){
                        flag=1;
                        system("clear");
                        cout<<"登录成功！"<<endl;
                        exit = 1;
                    }
                }
                i+=1;
            }
            if(flag==0){
                cout<<"用户名或者密码错误！"<<endl;
            }
            break;
        default:
            exit=1;
            break;
        }  
   }
   int keywordFlag;
    string keyword;
    int exit1=0;
    string content[log.contentNum*2];
    string _0_1;

    read1.open("/Users/shiyi/Desktop/robot/content.txt");
    for(int i=0;i<log.contentNum*2;i++){
        read1>>content[i];
        read1>>content[i+1];
        i+=1;
            }
    read1.close();

    while(!exit1){
        if(flag==1){
            B:
            keywordFlag=0;
            cout<<"---+---+---+---+---+---+---+---+---+---+---+---+---+"<<endl;
            cout<<"请回复关键字："<<endl;cin>>keyword;
            for(int i=0;i<log.contentNum*2;i++){
                if(keyword == content[i]){
                    cout<<"识别出关键字为 :"<<keyword<<endl;
                    cout<<"相关内容如下："<<endl;
                    cout<<content[i+1]<<endl;
                    keywordFlag=1;
                }
                i+=1;
            }
            if(keywordFlag==0){
                cout<<keyword<<"不是关键字"<<endl;
                cout<<"---+---+---+---+---+---+---+---+---+---+---+---+---+"<<endl;
                C:
                cout<<"返回登录请按 0"<<endl<<"退出系统请按 1："<<endl<<"继续输入请按 2：";
                cin>>_0_1;
                if(_0_1 == "1"){
                    system("clear");
                    return 0;
                }
                else if(_0_1 =="0"){
                    system("clear");
                    exit = 0;
                    goto A;
                }
                else if(_0_1 == "2"){
                    system("clear");
                    goto B;
                }
                else{
                    goto C;
                }
            }
        }   
        else{
            cout<<"请登录以使用系统！"<<endl;
            exit1=1;
        }
    }
    return 0;
}