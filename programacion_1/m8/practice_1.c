/*
	La función fclose(), utiliza el nombre externo de un archivo o la variable de este?
	- utiliza la variable de este.
	Y la función fprintf()?
	- tambien utiliza la variable creada.
	Siendo arch una variable FILE, explique la diferencia entre:
	arch = fopen(“archivo.txt”,”rt”);
	arch = fopen(“archivo.txt”,”wt”);
	- rt lee el contenido del archivo, wt crea el archivo si no existe, si existe lo pisa.
	La instrucción arch = fopen(“archivo.txt”,”wt”); presenta algún peligro 
	potencial?
	- si el archivo existia previamente, se pierde todo el contenido anterior.
*/