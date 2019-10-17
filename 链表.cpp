#include <iostream>
#include <stdlib.h>
using namespace std;

int showmenu(){
	int index=0;
	system("cls"); 
	cout<<"********************************************************"<<endl;
	cout<<"**************           菜单选择           ************"<<endl; 
	cout << "*********************************************************" << endl;
	cout << "***************  1.初始化或重置链表      ****************" << endl;
	cout << "***************  2.销毁链表              ****************" << endl;
	cout << "***************  3.链表中数据元素个数    ****************" << endl;
	cout << "***************  4.所指位序的元素值      ****************" << endl;
	cout << "***************  5.链表已存在元素的位序  ****************" << endl;
	cout << "***************  6.请输入元素,求直接前驱 ****************" << endl;
	cout << "***************  7.请输入元素,求直接后继 ****************" << endl;
	cout << "***************  8.在第i个位置插入元素   ****************" << endl;
	cout << "***************  9.删除第i个元素         ****************" << endl;
	cout << "***************  10.输出所输入的链表元素 ****************" << endl;
	cout << "***************  11.初始化并输入链表元素 ****************" << endl;
	cout << "***************  12.退出                 ****************" << endl;
	cout << "*********************************************************" << endl;
	cout<<"请输入"<<endl;
	cin>>index;
	return index;
}
struct lnote{
	int data;
	lnote *next;
}; 

lnote* head;
int charu(int location)
{
	lnote *pt=head;
	lnote *temp=(lnote*) malloc(sizeof(lnote));
	cout<<"请输入要插入的数值:";
	cin>>temp->data;
	for(int i=1;i<location;i++)
	pt=pt->next;
	temp->next=pt->next;
	pt->next=temp;
	return 0;
}
void csh(){
	head = (lnote*) malloc(sizeof(lnote));
	head->data = 0; 
	head->next=NULL;
	cout<<"初始化成功"<<endl; 
} 
void createlist(){
	head = (lnote*) malloc(sizeof(lnote));
	head->data = 0; 
	head->next=NULL;
	
	lnote* pt = head;
	
	for(int i = 1;i<=10;i++){
		lnote* temp;
		temp = (lnote*) malloc(sizeof(lnote));
		temp->data = i*10 + i;
		temp->next = NULL;
		pt->next = temp;
		pt = pt->next;
	}
	
}
void printlist(){
	lnote* pt = head;
	int len = 1;
	while(pt->next!=NULL){
		pt=pt->next;
		cout<<"此为第"<<len<<"个链表"<<pt->data<<endl;
		len++;
	}
	
}

int countlist(){
	lnote* pt = head;
	int len = 0;
	while(pt->next!=NULL){
		pt=pt->next;
		len++;
		
	}
	return len;
}
int getlocationbydata(int data){
	lnote* pt = head;
	int index = 0; 
	int flag = 1;
	while(pt->next!=NULL){
		index++;
		pt = pt->next;
		if(data==pt->data){
			return index;
			flag = 2;
		}
	}
	if(flag!=2){
		return 0;
	}
} 
int getdatabylocation(int location){
	if(location<=0){
		cout<<"输入的位置索引不正确，请重新输入！"<<endl;
		return 0;
	}
	if(location>countlist()){
		cout<<"输入的位置索引超过了链表的长度，请重新输入！"<<endl;
		return 0;
	}
	lnote* pt = head;
	int index = 0; 
	for(int i = 0;i<location;i++){
		pt=pt->next;
	}
	cout<<"当前第"<<location<<"个元素的值为："<<pt->data<<endl;
	return 0;
} 
int getprobydata(int data){
	int getindex = getlocationbydata(data);
	if(getindex==0){
		cout<<"当前元素"<<data<<"没有在链表中查询到，所有没有前驱数据"<<endl;
		return 0;
	}
	if(getindex==1){
		cout<<"当前元素"<<data<<"属于链表的第一个元素，没有前驱数据"<<endl;
		return 0;
	}
	lnote* pt = head;
	for(int i = 1;i<getindex;i++){
		pt = pt->next;	
	}
	cout<<"该元素"<<data<<"的直接前驱为:"<<pt->data<<endl;
}
int getnextbydata(int data){
	int getindex = getlocationbydata(data);
	if(getindex==0){
		cout<<"当前元素"<<data<<"没有在链表中查询到，所有没有后继数据"<<endl;
		return 0;
	}
	if(getindex==countlist()){
		cout<<"当前元素"<<data<<"属于链表的最后一个元素，没有后继数据"<<endl;
		return 0;
	}
	lnote* pt = head;
	for(int i = 1;i<getindex+2;i++){
		pt = pt->next;	
	}
	cout<<"该元素"<<data<<"的直接前后继为:"<<pt->data<<endl;
}
int deletebylocation(int location){
	int getindex = getlocationbydata(location);
	lnote* pt = head;
	if(getindex==0)
	{
		cout<<"删除失败"<<endl;
		return 0; 
	}
	for(int i = 1;i < getindex;i++){
		pt = pt->next;
	}
	pt->next = pt->next->next;
	cout<<"删除成功"<<endl;
	return 0; 
}
int main(){
	while(1){
		int index = showmenu(); 
		switch(index){
			case 1:{
				csh();
				system("pause");
				break;
			}
			case 2:{
				cout<<"删除成功"<<endl;
				system("pause");
				break;
			}
			
			case 3:{
			cout<<"共有"<<countlist()<<"个链表"<<endl;
				system("pause");
				break;
			}
			case 4:{
				int location;
				cout<<"请输入要查找的元素索引:";
				cin>>location;
				int getdata = getdatabylocation(location);
				system("pause");
				break;
			}
			case 5:{
				int data;
				cout<<"请输入要查找的值:";
				cin>>data;
				int getindex = getlocationbydata(data);
				 if(getindex!=0){
				 	cout<<"该值为第"<<getindex<<"数"<<endl;
				 }
				 else{
				 	cout<<"表中没有该值"<<endl;	
				 }
				system("pause");
				break;
			}
			case 6:{
				int data;
				cout<<"请输入要查找的元素:";
				cin>>data;
				int getdata = getprobydata(data);
				system("pause");
				break;
			}
			case 7:{
				int data;
				cout<<"请输入要查找的元素:";
				cin>>data;
				int getdata = getnextbydata(data);
				system("pause");
				break;
			}
			case 8:{
				int loc;
				cout<<"请输入要插入的位置:";
				cin>>loc;
				charu(loc);
				system("pause");
				break;
			}
			case 9:{
				int location;
				cout<<"请输入要删除的元素:";
				cin>>location;
				deletebylocation(location);
				system("pause");
				break;
			}
			case 10:{
				printlist();
				system("pause");
				break;
			}
			case 11:{
				createlist();
				cout<<"创建成功"<<endl;
				system("pause");
				break;
			}
			case 12:{
				exit(10);
				break;
			}
		}
	}	
	return 0;
}
