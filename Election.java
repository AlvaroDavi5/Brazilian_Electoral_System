import source.*;
import java.io.IOException;


public class Election {

	public static void main(String[] args) throws IOException
	{
		Utils util = new Utils();

		ElectionInfo candidatesEle = util.readFile(args[0]);
		ElectionInfo partiesEle = util.readFile(args[1]);

		System.out.println(candidatesEle.getData());
		System.out.println(partiesEle.getData());

		//
	}

}

