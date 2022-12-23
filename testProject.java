import java.util.Arrays;

public class testProject {
    public static void main(String[] args){
        double[] testArray = {37,5,3.3,6.66,12, 375.23, 115.2,348};
        int left = 0; int right = testArray.length - 1;
        Arrays.sort(testArray);
        for(int i = 0; i < testArray.length; i++){
            System.out.print(testArray[i] + ", ");
        }
        int even = testArray.length % 2;
        if(even == 0){
            int middle = testArray.length/2 - 1;
            double answer = (testArray[middle] + testArray[(middle + 1)])/2;
            System.out.println("Median: " + answer);
        } else {
            int middle = left + (right - left)/2;
            System.out.println("Median: " + testArray[middle]);
        }


    }
}