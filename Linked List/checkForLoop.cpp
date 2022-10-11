bool isThereLoop(Node* head)
{
  Node* first=head,*second=head;
  do
  {
    first=first->next;
    second=second->next->next;
    if(first==second) return true;
  }while(second!=NULL&&second->next!=NULL);
  return false;
}
