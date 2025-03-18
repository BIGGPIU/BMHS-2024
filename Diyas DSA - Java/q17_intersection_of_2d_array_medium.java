// 
// You are given a 2D array, you must find the character at the middle of the array and return it.

// For this problem you should always round Down.

// Restrictions:
// arrays will be the same length and width.
// 

import static java.lang.Math.floor;

public class q17_intersection_of_2d_array_medium {
    


    private char intersection(char [][] array) {
        return 97;
    }
















































































































    private char myown(char [][] array) {
        int centerY =  (int) floor((array.length)/2);
        int centerX =  (int) floor((array[0].length)/2);
        return array[centerY][centerX];
    }

    public void main(String[] args) {
        char [][][] qs = {
            {{'a', 'b', 'c'}, 
     {'d', 'e', 'f'}, 
     {'g', 'h', 'i'}},
     {{'a', 'b', 'c', 'd'}, 
     {'e', 'f', 'g', 'h'}, 
     {'i', 'j', 'k', 'l'}, 
     {'m', 'n', 'o', 'p'}},
     {{'a', 'b', 'c', 'd', 'e'}},
     {{'a'}, 
     {'b'}, 
     {'c'}, 
     {'d'}, 
     {'e'}},
     {{'a', 'b', 'c', 'd', 'e'}, 
     {'f', 'g', 'h', 'i', 'j'}, 
     {'k', 'l', 'm', 'n', 'o'}, 
     {'p', 'q', 'r', 's', 't'}, 
     {'u', 'v', 'w', 'x', 'y'}},
     {{'a', 'b'}, 
     {'c', 'd'}},
     {{'a', 'b', 'c', 'd'}, 
     {'e', 'f', 'g', 'h'}, 
     {'i', 'j', 'k', 'l'}},
     {{'a', 'b'}, 
     {'c', 'd'}, 
     {'e', 'f'}, 
     {'g', 'h'}, 
     {'i', 'j'}},
     {{'a', 'b', 'c', 'd', 'e', 'f'}, 
     {'g', 'h', 'i', 'j', 'k', 'l'}, 
     {'m', 'n', 'o', 'p', 'q', 'r'}, 
     {'s', 't', 'u', 'v', 'w', 'x'}, 
     {'y', 'z', 'a', 'b', 'c', 'd'}, 
     {'e', 'f', 'g', 'h', 'i', 'j'}},
     {{'a', 'b', 'c', 'd', 'e', 'f', 'g'}, 
     {'h', 'i', 'j', 'k', 'l', 'm', 'n'}, 
     {'o', 'p', 'q', 'r', 's', 't', 'u'}, 
     {'v', 'w', 'x', 'y', 'z', 'a', 'b'}, 
     {'c', 'd', 'e', 'f', 'g', 'h', 'i'}, 
     {'j', 'k', 'l', 'm', 'n', 'o', 'p'}, 
     {'q', 'r', 's', 't', 'u', 'v', 'w'}},
     {{'a'}}
        };
        for (int i = 0; i < qs.length ; i++) {
            if (myown(qs[i]) != intersection(qs[i])) {
                System.out.println("Failed testcase " + (i+1));
                return;
            }
        }
        System.out.println("You passed");
    }
}
