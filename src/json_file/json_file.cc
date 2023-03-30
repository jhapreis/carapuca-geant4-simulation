#include "json_file/json_file.hh"


JsonFile::JsonFile(std::string const& path)
:
    file_path(path)
{
    file_content = Read();

    json_document.Parse(file_content);
}


JsonFile::~JsonFile() = default;


char* JsonFile::Read(){

    std::string file_data;

    std::ifstream t(file_path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    
    auto c_string = new char[buffer.str().length()+1];

    strcpy(c_string, buffer.str().data());

    return c_string;
}


char* JsonFile::GetContent(){
    return file_content;
}


rapidjson::Document* JsonFile::GetDocument(){
    return &json_document;
}


int JsonFile::GetInt(const char* key){
    return json_document[key].GetInt();
}


float JsonFile::GetFloat(const char* key){
    return json_document[key].GetFloat();
}


double JsonFile::GetDouble(const char* key){
    return json_document[key].GetDouble();
}


const char* JsonFile::GetString(const char* key){
    return json_document[key].GetString();
}
