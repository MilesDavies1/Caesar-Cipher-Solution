#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>
using namespace std;
 
string encrypt(string message, int c)
{
  string result = "";
  for (int i=0;i<message.length();i++)
  {
    if(int(message[i])<65)
    {
        message[i] = message[i] + 1;
        continue;
    } 
    else if(int(message[i])>122)
    {
        message[i] = message[i] + 1;
        continue;
    }
    else if(int(message[i])>90 && message[i]<97)
    {
        message[i] = message[i] + 1;
        continue;
    }
    if (isupper(message[i])){
      result += char(int(message[i]+c-65)%26 +65);    
    }
    else if (message[i] != isupper(message[i])){
    char(toupper(message[i]));
    result += char(int(message[i]+c-65)%26 +65);  
    }
  }
  return result;
}
 
int main()
{
  string message;
  int c = 0;
  cout << "Enter a shift amount" << endl;
  cin >> c;
  cout << "Enter a message" << endl;
  //cin >> message;
  getline(cin >> ws, message);
  string ans = encrypt(message, c);
  int counter = 0;
  for(int i=0;i<ans.length();i++)
  {
    while(counter % 5 == 0 && counter !=0)
    {
    cout << ans[i] << " ";
    counter += 1; 
    }
    if(counter == 50)
    {
    cout << ans[i] << endl;
    counter = 0;    
    }
    else
    {
    cout << ans[i];
    counter += 1;
    }
  }
  return 0;
}
