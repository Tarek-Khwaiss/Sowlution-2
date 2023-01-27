public class Question1 {

    public static boolean validateEmail(String s) {

        // to check if an '@' symbol has occurred
        int flag1 = 0;

        // to check if a '.' symbol has occurred
        int flag2 = 0;

        // index to save the position of the index
        int index1 = 0, index2 = 0;

        // 1. check the length
        if (s.length() > 256)
            return false;

        // transform the string to a character array to loop over it (O(n) complexity)
        char[] email = s.toCharArray();

        for (int i = 0; i < s.length(); i++) {
            if (email[0] == '@' || email[s.length() - 1] == '@') {
                return false;
            }
            if (email[i] == '@') {
                // an occurance has already happend
                if (flag1 == 1) {
                    return false;
                }
                flag1 = 1;
                index1 = i;
            }
            if (email[i] == '.') {
                flag2 = 1;
                index2 = i;
            }
        }

        // last step: checking if the result is valid or not
        if (flag1 == 1 && flag2 == 1 && index2 > index1 + 1) {

            // email is valid
            return true;
        } else {
            return false;
        }

    }

    public static void main(String[] args) {

        // test cases
        System.out.println(validateEmail("john.doe@gmail.com")); // Returns true
        System.out.println(validateEmail("john@doe@gmail.com")); // false
        System.out.println(validateEmail("john@gmail.c")); // false
        System.out.println(validateEmail("john@.com")); // false

    }
}
