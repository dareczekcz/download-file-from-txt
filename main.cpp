#include <iostream>
#include <fstream>  // operation on file
#include <regex>

#include <curl/curl.h> // downloading with cURL

using namespace std;

int odc = -1 ;
int debug = 10 ;
string DestDir = "";
string name = "";
string DownUrl = ""; // example http://c.wrzuta.pl/whthd4451/5c4b4fdc000f3a76555c93b0
string AfterDownload;
string AfterAll;

int download_with_cURL();

char * string_to_c_char(string str){
    char tmp[str.size()+1];
	copy(str.begin(),str.end(), tmp);
	return tmp;
};
int tmp = 1;

int set_walue( string name , string value ){
//name na male znaki
 char char_name[name.size()+1] ;//= DownUrl.c_str(); //  char *url = "http://localhost/aaa.txt";
 copy(name.begin(),name.end(), char_name);

cout <<" set_value() | tmp"<< (tmp-1) <<"| name = "<< name <<" | value = "<< value <<endl ;
//tolower(name);

  char str1[] = "DestDir";
  int tmp = strcmp(char_name,str1);
  if ( tmp == 0){ cout <<"\n\tUstawiono "<<name<<" = "<<value<<" \n"; DestDir = value; };

  char str2[] = "name";
  tmp = strcmp(char_name,str2);
  if ( tmp == 0){ cout <<"\n\tUstawiono "<<name<<" = "<<value<<" \n"; name = value; };

  char str3[] = "DownUrl";
  tmp = strcmp(char_name,str3);
  if ( tmp == 0){ cout <<"\n\tUstawiono "<<name<<" = "<<value<<" \n"; DownUrl = value; // download_with_cURL();
   };

  char str4[] = "AfterDownload";
  tmp = strcmp(char_name,str4);
  if ( tmp == 0){ cout <<"\n\tUstawiono "<<name<<" = "<<value<<" \n"; AfterDownload = value; };

  char str5[] = "AfterAll";
  tmp = strcmp(char_name,str5);
  if ( tmp == 0){ cout <<"\n\tUstawiono "<<name<<" = "<<value<<" \n"; AfterAll = value; };

  char str6[] = "odc";
  tmp = strcmp(char_name,str6);
  if ( tmp == 0){ cout <<"\n\tUstawiono "<<name<<" = "<<value<<" \n"; odc = atoi(value.c_str()); };

  char str7[] = "debug";
  tmp = strcmp(char_name,str7);
  if ( tmp == 0){ cout <<"\n\tUstawiono "<<name<<" = "<<value<<" \n"; debug = atoi(value.c_str()); };
 /*  if (stricmp(buf.marka,zm1) == 0) // jesli sa takie same , ignoruje wielkosc liter
     if (strcmp(buf.marka,zm1) == 0) // jesli sa takie same

 // */
return 0;
};

 size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
};

download_with_cURL(){

// TODO (Właściciel#2#): fincja download_with_cURL wykorzystujaca zmienne globalne ...
// jezeli odc < 1 nie dopisuj do nazwy
//jezeli DestDir zawiera nazwe np. \cos\cos\nazwa.rozszezenie to nazwa=nazwa.rozszezenie



    CURL *curl;
    FILE *fp;
    CURLcode res;
    char *url ;//= DownUrl.c_str(); //  char *url = "http://localhost/aaa.txt";
    copy(DownUrl.begin(),DownUrl.end(), url);


	//char outfilename[FILENAME_MAX] = DestDir;//.c_str(); // char outfilename[FILENAME_MAX] = "C:\\bbb.txt";
	char outfilename[DestDir.size()+1];
	copy(DestDir.begin(),DestDir.end(), outfilename);
	// = DestDir;//.c_str(); // char outfilename[FILENAME_MAX] = "C:\\bbb.txt";
    curl = curl_easy_init();
    if (curl){
        fp = fopen(outfilename,"w"); // fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
        if(res != CURLE_OK)
          cout << "curl_easy_perform() res: "<<res<<" blad : "<< curl_easy_strerror(res)<<endl;
    };

if (odc > -1 ) odc++;
return 0;
};


// */
int main()
{
//system("pause");
 // FILE * pFile
  fstream file;


  file.open("do_pobrania_v2.txt");   //otwarcie pliku
  //file.open("do_pobrania.txt");   //otwarcie pliku

  // jezeli b³ad otwarcia pliku to poka¿ komunikat
  if(file.good() == false ){
    //printf("blad otwarcia pliku \"do_pobrania.txt\" \n");
    cout <<"blad otwarcia pliku \"do_pobrania_v2.txt\" \n";
  }else{ // otworzyliœmy plik
        cout <<"\nSkanowanie pliku";
      while ( (!file.eof() ) && ( !file.eof()) ){
        //pobierz linie(?)

        //regex [(A-Za-z):()];

cout << "\n\n\n# linia(?) "<<tmp++;
//gdañska tatarkiewicza ? Sprzedam ogródkek dzialkowy

    // TODO (Właściciel#1#): Poprawić wzorzec reg_egex   ...
    //opcja:wartosc
    //opcja: wartosc
    //  opcja:   wartosc
    // http://www.cplusplus.com/reference/regex/regex_match/

        string line;
         getline( file, line );
      //  cout << line;

if(debug > 10){ cout << " [150] "; };

        // Wzorzec
        const char *reg_esp = "\s{0,}([A-Za-z]{0,})\s{0,}:\s{0,}([A-Za-z0-9\.|\/]){0,}\s{0,}" ;
        //const char *reg_esp = "\s{0,}(A-Za-z)\s{0,}:\s{0,}(^:*?<>|)\s{0,}" ;
        //const char *reg_esp = "\s{0,}([A-Za-z\w]?[A-Za-z]{0,})\s{0,}:\s{0,}(^:*?<>|){0,}\s{0,}" ;
        //const char *reg_esp = "\s{0,}([A-Za-z]{0,})\s{0,}:\s{0,}(^:*?<>|){0,}\s{0,}" ;
       // const char *reg_esp = "\s{0,}([A-Za-z]{0,})\s{0,}:\s{0,}([[[:blank:]]A-Za-z\\0-9\/\-\=\[\]\;\'\,\~\!\@\#\$\%\^\&\(\)\_\+\}\{\]){0,}\s{0,}" ;
    //  \`\-\=\[\]\;\'\,\~\!\@\#\$\%\^\&\(\)\_\+\}\{\   A-Za-z1-9

if(debug > 10){  cout << " [157] ";};
//cout << regex_error();
        regex rgx(reg_esp) ; // 'regex' jest instancj¹ klasy szablonowej
                             // 'basic_regex' z argumentem typu 'char'.
//cout << regex_error();
if(debug > 10){  cout << " [160] "; };
        cmatch match ; // 'cmatch' jest instancj¹ klasy szablonowej
                       // 'match_results' z argumentem typu 'const char *'.


if(debug > 10){ cout << " [163] "; };

        const char *target =line.c_str();
/*
        std::string str;
        const char * c = str.c_str();

        const char *target  = "hjk : University of Turin " ;

        getline(file,target);

  */

if(debug > 10){ cout << " [175] "; };
       // cout <<"\t\t match.size() " << match.size() <<endl;
       // cout <<"\t\t regex_search( target, match, rgx )" << regex_search( target, match, rgx ) <<endl;
        //Identyfikuje wszystkie s³owa w 'target' rozdzielone przez znaki w 'reg_esp'.
      //      for( int a = 0 ; a < match.size() ; a++ ){
        //            string str( match[a].first, match[a].second ) ;
        //            cout << str << "\n" ;
          //  };




        if( regex_search( target, match, rgx ) )
        {
        //Jeœli istnieje s³owo oddzielone przez podane znaki
            cout <<"  :  [134] match.size() = "<<match.size();//<<" |";

                for( int a = 0; a < match.size() +1; a++ ){
                   // string str( match[a].first, match[a].second ) ;
                    cout <<" | match["<<a<<"] = "<< match[a] ;
                };
                cout << "| [190]"<<endl;

   /*         if( match.size() != 2 ){
                cout << "\nnie rozpoznane ustawienie | str"<<endl;
set_walue(match[1],match[2]);
                for( int a = 0 ; a < match.size() ; a++ ){
                    string str( match[a].first, match[a].second ) ;
                  cout << str ;
                };

            }else{*/
  //  match[1] = "x";
   // match[2] = "y";
               cout << "\n match[0] | match[1] | match[2] [202]\n ";
               cout << match[0] <<" | "<<match[1]<<" | "<<match[2] << " | "<<endl;
               set_walue(match[1],match[2]); // option , value
           // };

            // CURL

          }else{ cout << " brak wynikow ";}; //

        };// End of File

 // cout <<endl<<"zakonczono pobieranie"<<endl;

  // uruchomienie podanego programu

  cout <<"zakonczono dzialanie"<<endl;
  file.close();
  };// open file
set_walue("name","HunterxHuner");

    cout << "Hello world!" << endl;
    return 0;

}
