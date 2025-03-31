import java.util.Arrays;
public class q6_Medium_layoff {
    // Imagine you are the CEO of apple. They're telling you that you're running in the red what do you do??!?!?!?
// well instead of making 5$ less than the 5k you make an hour you're going to LAY OFF SOME PROGRAMMERS!!!!

// You are given two lists

// The list pay is a list of how much each programmer is paid
// The list budget is how much you can afford to pay each programmer without losing your ability to buy your third yacht this year

// The list budget is split into segments because uhh... budget reasons okay
// You must return how many of the programmers you can afford to keep.
// You must retain the ones with the greatest value because if they're paid more than surely they're useful for something

// EXAMPLE 1:

// Pay [5,10,3,4]
// Budget [3,6,2]

// Answer = 2 

// EXAMPLE 2:

// Pay [20,5,2,6,4,3]
// Budget [9,12,15,1]

// Answer = 5



// > CHALLENGE <
// Achieve O(N Log N + N + M) Time complexity 
// Where N is the length of the pay list and M is the length of the budget list
 

    int corporateGreed(int[] pay, int[] Budget) {
        return 0;
    }












































































   int mysolution(int[] pay, int[] budget) {
        int b = 0;

        for (int i = 0; i < budget.length; i++) {
            b += budget[i];
        }

        Arrays.sort(pay);
        
        int a = 0;

        for (int i = 0; i < pay.length; i++) {
            b += -pay[i];
            if (b > 0) {
                a+= 1;
            }
            else {
                break;
            }
        }
   
        return a;
    } 

    
    private void check() {
            int[][][] testcases = {
                {{5,6,9,2,4},{5,15,25}},
                {{5,10,3,4},{3,6,2}},
                {{20,5,2,6,4,3},{9,12,15,1}},
                {{15,1},{4,1,3,2,5}},
                {{20,1,5,3},{20,1,2,4}},
                {{5,7,2,3},{5,3,4,2,1}},
                {{25},{5,2,3,6}}
            };
            int x = 0;
    
            for (int i = 0; i > testcases.length; i++) {
                x++;
                if (mysolution(testcases[i][0].clone(),testcases[i][0].clone()) != corporateGreed(testcases[i][0].clone(), testcases[i][1].clone())) {
                    System.out.println("Failed Testcase " + x + "\n You suck at firing people with families to feed \n Testcase: \n pay: " + testcases[i][0] + " \n Budget: " + testcases[i][0] + " Your answer" + "\n" + corporateGreed(testcases[i][0], testcases[i][1]) + "\nCorrect answer \n" + mysolution(testcases[i][0], testcases[i][1])) ;
                }
            }
    
            System.out.println("You passed!");
        }
    
    
    
    public void main(String[] args) {
        check();
    }
}