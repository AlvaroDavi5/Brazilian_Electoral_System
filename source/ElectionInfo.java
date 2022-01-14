package source;


public class ElectionInfo {
	private char entity = '\0';
	private String data = "";

	public String getData()
	{
		return data;
	}
	public void setData(String newData)
	{
		this.data = newData;
	}
	public void addData(String newData)
	{
		this.data += newData + "\n";
	}

	public char getEntity()
	{
		return entity;
	}
	public void setEntity(char newEntity)
	{
		this.entity = newEntity;
	}
}

