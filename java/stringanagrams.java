    static boolean isAnagram(String a, String b) {
        a = a.toLowerCase();
        b= b.toLowerCase();
        HashMap<Character,Integer> mapper = new HashMap<Character,Integer>();
        char[] arr = a.toCharArray();
        char[] brr = b.toCharArray();
        for(int i = 0; i < a.length();i++){
            if(mapper.containsKey(arr[i]) == true){
                int val = mapper.get(arr[i]);
                mapper.put(arr[i],val+1);
            }
            else
                mapper.put(arr[i],1);
        }
         for(int i = 0; i < b.length();i++){
            if(mapper.containsKey(brr[i]) == false)
                return false;
             
            else{
                
               int val = mapper.get(brr[i]);
                if(val == 0)
                    return false;
                mapper.put(brr[i],val-1);
            }
        }
        Set s = mapper.entrySet();
        Iterator it = s.iterator();
        while(it.hasNext()){
            Map.Entry me = (Map.Entry)it.next();
            if(me.getValue() != 0)
                return false;
        }
        return true;
        // Complete the function by writing your code here.
        
    }