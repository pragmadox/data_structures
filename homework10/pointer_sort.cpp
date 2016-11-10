void traverse_structure(structure_pointer p)
{
    cout << p->int_data << ", ";
    if(p->next!=NULL)
        traverse_structure(p->next);
}

for(int i=0; i<10; i++)
{
    structure_pointer p;
    p=get_structure(i+3, char('a'+i))
    q->next=p;
    q=p;
}

int main()
{
    structure_pointer head, q, p;

}