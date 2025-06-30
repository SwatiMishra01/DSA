int search(int arr[],int n,int num)
{
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num)
        return i;
    }
    return -1;
}
