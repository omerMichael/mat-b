#include <string>
#include <iostream>
using namespace std;


namespace ariel{
    string create_pref(int size, char s1, char s2){ 

        if (size==1){
            string p = ""; 
            p += s1;
            return p;
        }

        string ans = "";
        int i = 0;
        char symbol = s1;

        //sirsor s @@ godel h pref
        while(i < size){

            ans += symbol;
            symbol = (symbol == s1)? s2 : s1;
            i++;

        }
        return ans;
    }

    string create_post(int size, char s1, char s2){ 
        if(size %2==1) {
            return create_pref(size , s1 , s2);
        } else {
            //mone cfilot cod
            return create_pref(size , s2 , s1);
        }
    }

    string mat (int column , int row , char s1 , char s2){

        /*
9 7  cols gt rows
@@@@@@@@@ 0 
@-------@ 1
@-@@@@@-@ 2
@-@---@-@ 3  pref = 4 == "rows/2~ + 1 
@-@@@@@-@ 4  # reverese
@-------@ 5
@@@@@@@@@ 6

7 9 cols lt rows
@@@@@@@ 0
@-----@ 1
@-@@@-@ 2
@-@-@-@ 3 prefix = 4 == rows/2 && rows gt cols
@-@-@-@ 4 ???  from i = 0 to cols/2 + 1:
@-@-@-@ 5 ???       append(pref(k) + pref(n-k))
@-@@@-@ 6 # reverse
@-----@ 7 
@@@@@@@ 8

        */

        string MAT = "";
       

        int pref_size = 1;
        //0 or 1
        int framei = 0;
        int i = 0;
        string sym;

        while(i < row){

            MAT.append(create_pref(pref_size,s1,s2));

            cout << pref_size << endl;
            sym = "";
            if((framei++) %2== 0){
                sym += s1;
            }else{
                sym += s2;
            }
            for (int j = pref_size; j < column - (2 * pref_size); j++){

                MAT.append(sym);
            }

            if((pref_size == row / 2) && row > column){

                cout << "implement row gt col"<<endl;
            }
            else if (pref_size == (row/2 +1)){

                cout << "implement"<<endl;
            }



            MAT.append(create_post(pref_size,s1,s2));
            MAT.append("\n");
            i++;
            pref_size++;
        }
        

        return MAT;
    }

    
}
