Node* tmp = head;
   while(head){
       if(tmp == head->next)
           return true;
       head = head->next;
   }
   return false;