#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"



class JsonFile{

    public:
        JsonFile(std::string const& path);
        ~JsonFile();
        char* GetContent();
        rapidjson::Document* GetDocument();
        
        int GetInt(const char* key);
        float GetFloat(const char* key);
        double GetDouble(const char* key);
        const char* GetString(const char* key);

    private:
        char* Read();
        char* file_content;
        std::string file_path;
        rapidjson::Document json_document;
};
