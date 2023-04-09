// Accepted and beats 100%

bool isValid(char * s){
    
   char *stack = malloc(sizeof(*s) * strlen(s));
    char *start = stack;
   
    if( strlen(s) % 2  != 0)
        return false;

    int opened=1;    
    while (*s) {
        if (*s == '(' || *s == '{' || *s == '[') {
            *stack = *s;
            stack++;
            
        } 
        else if ( (stack > start) )
        {

                // **** here --stack is happens only for one of the case.*****
                if ((*s == ')' && *--stack != '(') ||
                   (*s == '}' && *--stack != '{') ||
                   (*s == ']' && *--stack != '['))
                 {
                    return false;
            
                 }
                

        }
        else
            opened = 0;
        s++;
    }
    // if( start[0] != '(' && start[0] != '{' && start[0] != '[' )
    //      return false;
    
        return (stack == start)&&opened;

}  


// Accepted solution
int getType(char c) {
    int idx = 0;
    
    switch (c) {
        case '(':
        idx = 0;
        break;
        case '{':
        idx = 1;
        break;
        case '[':
        idx = 2;
        break;
        case ')':
        idx = 3;
        break;
        case '}':
        idx = 4;
        break;
        case ']':
        idx = 5;
        break;
        default:
        break;          
    }    
    return idx;
}

bool isValid(char * s){
    
   char paren[] = { '(', '{', '[', ')', '}', ']' };
    int len = strlen(s);
    char *valid = (char*)calloc(len, sizeof(char));
    int k = 0;
    
    if(s == NULL || len == 1) 
        return false;
    if (len == 0)
        return true;
    
    for (int i=0; i<len; i++) {
        int type = getType(s[i]);
        
        if (type < 3) {
            valid[k++] = s[i];
        } else {
            if (k>0 && valid[k-1] == paren[type-3]) {
                k--;
            } else {
                return false;
            }                
        }
    }
    return (k == 0) ? true: false; 
}
