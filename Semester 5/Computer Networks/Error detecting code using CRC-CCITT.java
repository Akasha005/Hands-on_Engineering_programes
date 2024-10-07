import java.io.*;

class Crc {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] data;
        int[] div;
        int[] divisor;
        int[] rem;
        int[] crc;
        int data_bits, divisor_bits, tot_length;

        System.out.println("Enter number of data bits: ");
        data_bits = Integer.parseInt(br.readLine());
        data = new int[data_bits];
        System.out.println("Enter data bits: ");
        for (int i = 0; i < data_bits; i++) {
            data[i] = Integer.parseInt(br.readLine());
        }

        System.out.println("Enter number of bits in divisor: ");
        divisor_bits = Integer.parseInt(br.readLine());
        divisor = new int[divisor_bits];
        System.out.println("Enter Divisor bits: ");
        for (int i = 0; i < divisor_bits; i++) {
            divisor[i] = Integer.parseInt(br.readLine());
        }

        tot_length = data_bits + divisor_bits - 1;
        div = new int[tot_length];
        rem = new int[tot_length];
        crc = new int[tot_length];

        // Append data bits and 0s to div array
        for (int i = 0; i < data.length; i++) {
            div[i] = data[i];
        }

        System.out.print("Dividend (after appending 0's) is: ");
        for (int i = 0; i < div.length; i++) {
            System.out.print(div[i]);
        }
        System.out.println();

        // Initialize remainder with dividend
        for (int j = 0; j < div.length; j++) {
            rem[j] = div[j];
        }

        // Perform division
        rem = divide(div, divisor, rem);

        // Generate CRC by XORing remainder with dividend
        for (int i = 0; i < div.length; i++) {
            crc[i] = (div[i] ^ rem[i]);
        }

        System.out.println();
        System.out.println("CRC code: ");
        for (int i = 0; i < crc.length; i++) {
            System.out.print(crc[i]);
        }

        // Error Detection
        System.out.println();
        System.out.println("Enter CRC code of " + tot_length + " bits: ");
        for (int i = 0; i < crc.length; i++) {
            crc[i] = Integer.parseInt(br.readLine());
        }

        // Initialize remainder with received CRC code
        for (int j = 0; j < crc.length; j++) {
            rem[j] = crc[j];
        }

        // Perform division for error detection
        rem = divide(crc, divisor, rem);

        // Check for errors
        boolean error = false;
        for (int i = 0; i < rem.length; i++) {
            if (rem[i] != 0) {
                System.out.println("Error detected");
                error = true;
                break;
            }
        }
        if (!error) {
            System.out.println("No Error detected");
        }

        System.out.println("THANK YOU.... :)");
    }

    static int[] divide(int div[], int divisor[], int rem[]) {
        int cur = 0;
        while (true) {
            for (int i = 0; i < divisor.length; i++) {
                rem[cur + i] = (rem[cur + i] ^ divisor[i]);
            }
            while (rem[cur] == 0 && cur != rem.length - 1) {
                cur++;
            }
            if ((rem.length - cur) < divisor.length) {
                break;
            }
        }
        return rem;
    }
}
