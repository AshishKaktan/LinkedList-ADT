#include<iostream>
#include<stdlib.h>
using namespace std;

struct list {
	int value;
	struct list *next;
}*start=NULL;

class insert{
   
public: 
   	
 	void beg(int n){
		struct list *temp = new list();

		temp->value=n;
		temp->next=NULL;

		if(head==NULL){
		start=temp;
		}
		else{
		
		temp->next=start;
		start=temp;
		}	
	}

	void end(int n) {
	
		if(start==NULL)
		beg(n);
		else{
		 struct list *temp = new list();
		 struct list *tempp =start;
		 temp->value=n;
		 temp->next=NULL;
		 
		 while(tempp->next!=NULL){
		 	tempp=tempp->next;
		 }
		 tempp->next=temp;
		}
	}

	void mid(int n,int pos){
		if(start==NULL || pos ==1){
		beg(n);
		}
		else{
		int count=1;
		struct list *temp=new list();
		temp->value=n;
		struct list *p = start;
		struct list *q;
		
		while(p!=NULL && count<pos){
			
			q=p;
			p=p->next;
			count++;
		
		}
		q->next=temp;
		temp->next=p;
		}
	}	
}; 

class search{
public:
	int find(int n,struct list* head){
		struct list *temp = head;
		int pos=1;
		while(temp!=NULL && temp->value!=n){
			temp=temp->next;
			pos++;
		}
		if(temp==NULL)
		return -1;
		else
		return pos;
		
	}
	int getnth(int n,struct list* head){
		struct list *temp=head;
		struct list *temp1;
		int count=1;
		
		while( temp!=NULL && count<n )
		{
			temp1=temp;
			temp=temp->next;
			count++;
		}
		if(temp!=NULL)
		return temp->value; // return count for position
		else
		return temp1->value;
	}
	int getnthlast(int n,struct list* head){	
							
		struct list *temp=head;
		struct list *temp1=head;
		int count=1;

		while(temp!=NULL && count<=n){
			temp=temp->next;
			count++;
		}
		while(temp!=NULL){
			temp1=temp1->next;
			temp=temp->next;
		}
		return temp1->value; //return count for position
	}
	
	int getmid(struct list* head){
		struct list *slow=head;
		struct list *fast=head;
		
		while(fast!=NULL && fast->next!=NULL){
			slow=slow->next;
			fast=fast->next->next;
		}
		return slow->value;
	}
	
};

class print{
public:
	void printlist(struct list* head) {
		struct list *temp=head;
		if(temp==NULL){
			cout<<"Empty List\n";
		}
		else{
			while(temp!=NULL){
			cout<<temp->value<<" ";
			temp=temp->next;
			}
		}
	}
	
	void oddpos(struct list* head){
		struct list *temp = head;
		while(temp!=NULL){
			cout<<temp->value<<" ";
			if(temp->next!=NULL)
				temp=temp->next->next;
			else
				temp=temp->next;
		}
	}
	
	void evenpos(struct list* head){
		struct list *temp = head->next;
		while(temp!=NULL){
			cout<<temp->value<<" ";
			if(temp->next!=NULL)
				temp=temp->next->next;
			else
				temp=temp->next;
		}
	}
	
	void reverse(list* head){
		if(head==NULL)
			return ;
		reverse(head->next);
		cout<<head->value<<" ";		
	}
	
};

class listoperation{
	public:
	void reverselist(struct list* head) {
		struct list* prev=NULL;
		struct list* current=head;
		struct list* next;
		while(current!=NULL){
			next=current->next;
			current->next=prev;
			prev=current;
			current=next;
		}
		start=prev;
	}
	int occurrence(int no,struct list* head){
		struct list* temp=head;
		int count=0;
		while(temp!=NULL){
			if(temp->value==no)
			count++;
			temp=temp->next;
		}
		return count;
	}
};

class del{
	search s;
	public:
		void beg(struct list *head){
			if(head!=NULL){
				struct list *temp=head;
				start=start->next;
				free(temp);
			}
		}
		void last(struct list* head){
			struct list *temp=head;
			while(head->next!=NULL){
				temp=head;
				head=head->next;
			}
			temp->next=NULL;
			free(head);
		}
		void delpos(int pos,struct list *head){
			
			if(pos==1){
				beg(head);
			}
			else{
				int count=1;
				struct list* temp=head;
				struct list* prev=NULL;
				while(temp->next!=NULL && count<pos){
					prev=temp;
					temp=temp->next;
					count++;
				}
				
				if(temp->next==NULL){
					prev->next=NULL;
					free(temp);
				}
				else{
					prev->next=temp->next;
					temp->next=NULL;
					free(temp);
				}
			}
		}
		void element(int no,struct list* head){
			int pos=s.find(no,head);
			if(pos!=-1)
			delpos(pos,head);
		}
		void deletelist(struct list* head){
			struct list* temp=head;
			while(head!=NULL){
				head=head->next;
				temp->next=NULL;
				free(temp);
			}
			start=NULL;
		}
};

int main(){
	insert in;
	search s;
	print p;
	listoperation pp;
	del d;	
	in.beg(2);
	in.beg(2);
	in.beg(9);
	in.beg(9);
}
