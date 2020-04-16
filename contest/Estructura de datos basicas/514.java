import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int nblock = -1;
		//Si no lo inicializo me da error
		while((nblock==sc.nextInt())&&(nblock!=0)){
			int[] vector=new int[nblock];
			while ((vector[0]==sc.nextInt()) && (vector[0]!=0)) {
				for (int i = 0; i < nblock; i++) {
					vector[i]=sc.nextInt();
				}
			}
			
		}
	}

	
	public static void order(int [] vector){
		Stack<Integer> cola=new Stack<Integer>();
		int pos= 0;
		for (int i=0;i<vector.length;i++){
			cola.push(vector[i]);{
			while (!cola.isEmpty() && pos<vector.length && cola.peek()==vector[pos]){
				cola.pop();
				pos++;
			}
		}
			if(cola.isEmpty()){
				System.out.println("Yes");
			} else {
				System.out.println("No");
			}
			
	}
	
	}
}