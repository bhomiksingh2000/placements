Node* segregate(Node *head) {
        Node* dummy1=new Node(-1) ;
        Node* zero=dummy1;
        
        Node* dummy2=new Node(-1) ;
        Node* one=dummy2;
        
        Node* dummy3=new Node(-1) ;
        Node* two=dummy3;
        
        Node* temp=head;
        
        bool f1=false;
        bool f2=false;
        bool f3=false;
        
        while(temp!=NULL)
        {
            if(temp->data==0)
            {   f1=true;
                zero->next=temp;
                zero=zero->next;
            }
            else if(temp->data==1)
            {   f2=true;
                one->next=temp;
                one=one->next;
            }
            else
            {   f3=true;
                two->next=temp;   
                two=two->next;
            }
            
          temp=temp->next;
        }
        
        if(f1==true && f2==true && f3==true)
        { 
          zero->next=dummy2->next;
          one->next=dummy3->next;
          two->next=NULL;
          return dummy1->next; 
        } 
        
        if(f1==false && f2==true && f3==true)
        { 
           one->next=dummy3->next;
           two->next=NULL;
           return dummy2->next; 
        } 
        
        if(f1==true && f2==false && f3==true)
        { 
           zero->next=dummy3->next;
           two->next=NULL;
           return dummy1->next; 
        } 
        
        if(f1==true && f2==true && f3==false)
        { 
           zero->next=dummy2->next;
           one->next=NULL;
           return dummy1->next; 
        } 
    }