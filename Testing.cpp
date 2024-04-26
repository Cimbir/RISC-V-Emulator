#include "Testing.h"

Testing::Testing(ParseFile parf){
    pf = parf;
}

bool Testing::TestDefault(string filename){
    Build b = pf.getBuild(filename);

    stringbuf resbuf(ios::out);
    auto oldresbuf = cout.rdbuf(std::addressof(resbuf));

    b.Run();

    cout.rdbuf(oldresbuf);
    string resOutput = resbuf.str();

    string ansOutput = getAnswer("java -jar venus.jar " + filename);

    cout << "RESULT : " << resOutput << endl;
    cout << "ANSWER : " << ansOutput << endl;

    return resOutput == ansOutput;
}
void Testing::TestAll(){
    string path = "Tests/default_commands";
    int passed = 0;
    int count = 0;
    for(auto& entry : filesystem::directory_iterator(path)){
        cout << "TEST " << (count+1) << " : " << entry.path() << endl;
        count++;
        if(TestDefault(entry.path())){
            cout << "===| SUCCESS |===" << endl;
            passed++;
        }else{
            cout << "===| FAILURE |===" << endl;
        }
    }
    cout << "=======| " << passed << "/" << count << " PASSED |=======" << endl;
}

string Testing::getAnswer(string command) {
   char buffer[128];
   string result = "";

   // Open pipe to file
   FILE* pipe = popen(command.c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }

   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
      if (fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }

   pclose(pipe);
   return result;
}