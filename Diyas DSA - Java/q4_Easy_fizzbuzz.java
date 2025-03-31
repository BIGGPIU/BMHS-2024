public class q4_Easy_fizzbuzz {
// You are given a set of numbers from 1 through 100. 
// for every number that can be divided by 3 replace it with the word "fizz"
// for every number that can be divided by 5 replace it with the word "buzz"
// if a number is divisible by 3 and 5 replace it with the word "fizzbuzz"
// YOU MUST EDIT THE LIST IN PLACE - meaning you cannot return a new list

// EXAMPLE 1

// n = 15
// n[14] = fizzbuzz

// EXAMPLE 2

// n = 9
// n[8] = fizz

// EXAMPLE 3

// n = 7
// n[6] = 7

// suggested approaches:
// list comparison, check if float is an integer

    void fizzbuzz(String[] testList) {

    }






































    void check() {
        String answer[] =  {"1", "2", "fizz", "4", "buzz", "fizz", "7", "8", "fizz", "buzz", "11", "fizz", "13", "14", "fizzbuzz", "16", "17", "fizz", "19", "buzz", "fizz", "22", "23", "fizz", "buzz", "26", "fizz", "28", "29", "fizzbuzz", "31", "32", "fizz", "34", "buzz", "fizz", "37", "38", "fizz", "buzz", "41", "fizz", "43", "44", "fizzbuzz", "46", "47", "fizz", "49", "buzz", "fizz", "52", "53", "fizz", "buzz", "56", "fizz", "58", "59", "fizzbuzz", "61", "62", "fizz", "64", "buzz", "fizz", "67", "68", "fizz", "buzz", "71", "fizz", "73", "74", "fizzbuzz", "76", "77", "fizz", "79", "buzz", "fizz", "82", "83", "fizz", "buzz", "86", "fizz", "88", "89", "fizzbuzz", "91", "92", "fizz", "94", "buzz", "fizz", "97", "98", "fizz", "buzz"};
        String numbers[] = {
            "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
            "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
            "21", "22", "23", "24", "25", "26", "27", "28", "29", "30",
            "31", "32", "33", "34", "35", "36", "37", "38", "39", "40",
            "41", "42", "43", "44", "45", "46", "47", "48", "49", "50",
            "51", "52", "53", "54", "55", "56", "57", "58", "59", "60",
            "61", "62", "63", "64", "65", "66", "67", "68", "69", "70",
            "71", "72", "73", "74", "75", "76", "77", "78", "79", "80",
            "81", "82", "83", "84", "85", "86", "87", "88", "89", "90",
            "91", "92", "93", "94", "95", "96", "97", "98", "99", "100"
        };

        boolean flag = false;

        fizzbuzz(numbers);

        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i].equalsIgnoreCase(answer[i])  ) {
                flag = true;
            }
        }
        if (flag == true) {
            System.out.println("No way you failed fizzbuzz");
        }
        else {
            System.out.println("You passed!");
        }

    }


    public void main(String[] args) {
        check();
    }
}
