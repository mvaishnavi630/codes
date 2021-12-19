int minSwaps(string s) 
    {
        int balance=0;
        int j=s.size()-1;
        int x=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='[')
            {
                balance++;
            }
            else
            {
                balance--;
            }
            
            
            if(balance<0)
            {
                
                while(i<j && s[j]!='[')
                {
                    j--;
                }
                
                swap(s[i],s[j]);
                x++;
                balance+=2;
            }
            
            
        }
        return x;
    }