#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <iterator>

std::ifstream fin;
std::ofstream fout;


struct contact
{ 
  std::string name;
  std::string lastname;
  std::string address;
  std::string phone;

} obj;

std::map <int, contact> mymap;

std::map <int, contact> mymap2;


void read()
{
 std::cout << "here are your contacts" << std::endl;

  for (std::map<int, contact> :: iterator it = mymap.begin(); it != mymap.end(); ++it)
 {

  std::cout << "name:"     << "  " << it->second.name << std::endl;
  std::cout << "lastname:" << "  " << it->second.lastname << std::endl;
  std::cout << "address:"  << "  " << it-> second.address<< std::endl;
  std::cout << "phone:"    << "  " << it-> second.phone<< std::endl;

 }

	}



bool check(int key)
{
      
 for (std::map<int, contact> :: iterator it = mymap.begin(); it != mymap.end(); ++it)
 
 {
  
  if(it-> first == key)
  {	 	  
	  return false;
  }
	}
 
 return true;
 


}




void getcontacts()
{
	
fin.open("Code.txt");

 if(fin.is_open())
 {

   std::string str;
   while(!fin.eof())
   {
        fin >> str;
	 int x;
         std::istringstream s(str);
         s >> x;
	

        fin >> str;
	if (str == "name:")
	{
		fin >> str;
		obj.name = str;
	}


        fin >> str;
	if (str == "lastname:")
	{
		fin >> str;
		obj.lastname = str;
          
	}

	fin >> str;
	if (str == "address:")
	{
		
		
		fin >> str;
		obj.address = str;
           
	}

	
        fin >> str;
	if (str == "phone:")
	{
		fin >> str;
		obj.phone = str;
		
	        mymap.emplace(x, obj);
		

             
	}

   }
  



fin.close();

 }





}


void mainsave(int key)
{
	 for (std::map<int, contact> :: iterator it = mymap2.begin(); it != mymap2.end(); ++it){
         fout << "\n";
	 fout << key;
	 fout << "\n";
	 fout << "name: ";
	 fout << it->second.name;
	
	 
	 fout << "\n";

	 fout << "lastname: ";	 
	 fout << it->second.lastname;
	 fout << "\n";
         
	 fout << "address: ";	
	 fout << it->second.address;
	 fout << "\n";
	 
	 fout << "phone: ";	
	 fout << it->second.phone;
	 fout << "\n";
	 
 }



}





void save()
{

	
	fout.open("Code.txt");
	 
         
	
   for (std::map<int, contact> :: iterator it = mymap.begin(); it != mymap.end(); ++it){
 
	fout << it-> first;
	fout << "\n";
	 fout << "name: ";
	 fout << it->second.name;

	 fout << "\n";

	 fout << "lastname: ";	 
	 fout << it->second.lastname;
	 fout << "\n";
         
	 fout << "address: ";	
	 fout << it->second.address;
	 fout << "\n";
	 
	 fout << "phone: ";	
	 fout << it->second.phone;
	 fout << "\n";
	 
 }



 fout.close();

}








void add(int key)
{
  	
  std::string name;
  std::string lastname;
  std::string address;
  std::string phone;
  
   
 
  
  std::cout << "enter your name";
  std::cin >> name;
  obj.name = name;
  



  
  std::cout << "enter your lastname";
  std::cin >> lastname;
  obj.lastname = lastname;




  std::cout << "enter your address";
  std::cin >> address;
  obj.address = address;
   




  std::cout << "enter your phone";
  std::cin >> phone;
  obj.phone = phone;

 mymap2.emplace(key, obj);
 


}
 

void del()
{
	int key;
	std::string str;
	std::cout << "wiche one do you want to change and what exactly?";
	std::cin >> key;
	std::cin >> str;
            
	  for (std::map<int, contact> :: iterator it = mymap.begin(); it != mymap.end(); ++it)
	 {

		 if(key == it-> first && str == "lastname" )
		 {
			
			 it-> second.lastname = "                                      ";
			 it-> second.lastname = ".";

		 }
	 

       save(); 
        
                   if(key == it-> first && str == "name") 
		   {
			   std::cout << "name";
			   it-> second.name = "                                          ";
		           it-> second.name = ".";
		   }	   

 
       save();


              
   if(key == it-> first && str == "address") 
		   {
			   it-> second.address = "                                          ";
		           it-> second.address = ".";

		   }	   

 
       save();



   if(key == it-> first && str == "phone") 
		   {
			   it-> second.phone = "                                          ";
		           it-> second.phone = ".";

		   }	   

 
       save();

    


  if(key == it-> first && str == "all")
  {
 it-> second.name = "                                             ";
 it-> second.lastname = "                                         ";
 it-> second.address = "                                          ";
 it-> second.phone = "                                            ";
it-> second.name = ".";
it-> second.lastname = ".";
it-> second.address = ".";
it-> second.phone = ".";

  }
  save();

}

}



void change()
{

  std::string newname;
  std::string newlastname;
  std::string newaddress;
  std::string newphone;




	int key;
	std::string str;
	std::cout << "wiche one do you want to change and what exactly?";
	std::cin >> key;
	std::cin >> str;
        

    for (std::map<int, contact> :: iterator it = mymap.begin(); it != mymap.end(); ++it)
    {
	    
          if(key == it-> first && str == "name") 
	  {
		  std::cout << "enter the new name";
		  std::cin >> newname;
		  it->second.name = newname;
	  }

        save();

    
       
          if(key == it-> first && str == "lastname") 
	  {
		  std::cout << "enter the new lastname";
		  std::cin >> newlastname;
		  it->second.lastname = newlastname;
	  }

          save();

    
    
       
          if(key == it-> first && str == "address") 
	  {
		  std::cout << "enter the new address";
		  std::cin >> newaddress;
		  it->second.address = newaddress;
	  }

          save();

    
       
          if(key == it-> first && str == "phone") 
	  {
		  std::cout << "enter the new phone";
		  std::cin >> newphone;
		  it->second.phone = newphone;
	  }

          save();

    
    
     if(key == it-> first && str == "all") 
	  {
		  std::cout << "enter the new name" << std::endl;
		  std::cin >> newname;
		  it->second.name = newname;

                  std::cout << "enter the new lastname" << std::endl;
		  std::cin >> newlastname;
		  it->second.lastname = newlastname;
                  
		  std::cout << "enter the new address" << std::endl;
		  std::cin >> newaddress;
		  it->second.address = newaddress;

	          std::cout << "enter the new phone number" << std::endl;
		  std::cin >> newphone;
		  it->second.phone = newphone;

	  
	  
	  
	  
	  
	  
	  }

          save();

    
    
    
    
    }


}


 










int main()
{

 
 fout.open("Code.txt" , std::ofstream::app);
 

 if(!fout.is_open())
	std::cout << "could not open file ";

 else
	  std::cout << "your file is open" << std::endl;


 
again:

 std::string command;
 std::cin >> command;
 

 if(command == "add")
 {
	  getcontacts();
	  int key;
          std::cin >> key;
	  if (check(key))
	  {
          add(key); 
 
 std::string command2;
 std::cout << "save or not";
 std::cin >> command2; 


 
if(command2 == "save")
{ 
	
       mainsave(key);	
}
 }
    else
        std::cout << "the contact of that key number already exist" << std::endl;

  
  }



if(command == "delete")
{
	getcontacts();
	
	del();
}




  if(command == "change")
{	
	getcontacts();

        change();
}

if(command == "read")
{
	getcontacts();

	read();
}

std::cout << "do you want to continue yes/no" << std::endl;
std::string str;
std::cin >> str;
if(str == "yes")
{
	goto again;
}
else
   std::cout << "good work ";
 

}
