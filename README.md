
#### TODO

* [x] Implement constructor for the _Candidate_ and _Party_ classes
* [x] Implement getters and setters for the _Candidate_ and _Party_ classes
* [x] Implement methods to display/save reports about the candidates and parties lists in _ElectionInfo_ class
* [ ] Create a JAR file called `vereadores.jar` with the compiled classes and a `MANIFEST.mf` file
	> The MANIFEST file will define the main class  
	> The _main_ method of the **Main** class must receive the following parameters:  
		- `candidates_file`: the path to the candidates file  
		- `parties_file`: the path to the parties file  
		- `election_date`: the election date  
	> The execution command is:  
		`java -jar vereadores.jar <candidates_file> <parties_file> <election_date>`  
* [ ] Create a Ant `build.xml` file

___

# ABOUT

by _Álvaro Davi S. Alves_ - **2020101874**
and _Elder Storck_ - **2020······**

First assignment for the discipline  ```Programação III (Object-Oriented Programming)```.


#### Computer Engineering Class :computer:

### Universidade Federal do Espirito Santo ([UFES](https://ufes.br))


<img src="./docs/img/marca_ufes.png" alt="ufes logo" height="150px" width="250px">   

---

## How to run

To run this project, you need to have the [JDK version 11](https://www.oracle.com/br/java/technologies/javase/jdk11-archive-downloads.html) or higher installed.  

After installing the JDK, you can run the project by typing the following command in the terminal:  
```sh
#to compile the project
javac -d ./bin/ ./Election.java

# to run the project
java ./bin/Election ./input/data/candidatos.csv ./input/data/partidos.csv 15/11/2020
```
