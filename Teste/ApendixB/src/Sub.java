
public class Sub implements Operatie {

	@Override
	public void evaluate(Integer a, Integer b) {
		
		Integer x = a - b;
		System.out.print(Integer.toString(x));

	}

}
