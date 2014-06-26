public class ApendixB {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		if ( args.length < 3 )
		{
			System.out.println("Eroare");
		}
		
		String classNameToBeLoaded = args[0];
		Integer a = Integer.parseInt(args[1]);
		Integer b = Integer.parseInt(args[2]);

		ClassLoader myClassLoader = ApendixB.class.getClassLoader();
		try {
			Class<?> myClass = myClassLoader.loadClass(classNameToBeLoaded);
			Object instance = myClass.newInstance();
			
			if("Add".equals(classNameToBeLoaded))
			{
				((Add)instance).evaluate(a, b);
				
			} else if("Sub".equals(classNameToBeLoaded))
			{
				((Sub)instance).evaluate(a, b);
				
			} else 
			{
				System.out.println("Eroare");
			}
			
			
		} catch (ClassNotFoundException | InstantiationException | IllegalAccessException e) {
			System.out.println("Eroare");
		}
		
	}

}
