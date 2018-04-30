Node* Delete(Node* head, int position){
	
	int i = 0, n = 0, cont = 0;
	Node *ans, *aux1, *previous;
	
	if(head->next==NULL){
		ans = NULL;
	}else if(position==0){
		ans = head->next;
	}else{
		
		for(i=0;i<=position;i++){
			if(i=0){
				aux1 = head;
				previous = head;
				
			}else{
				aux1 = aux1->next;
				if(n==position){
					if(aux1->next==NULL){
						previous->next = NULL;
					}else{
						previous->next = aux1->next;
					}
				}
				if(i==position-1){
					previous = aux1;
				}
			}
			
		}	
	}
	return ans;
}
