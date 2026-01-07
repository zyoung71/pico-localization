#pragma once

#include <storage/FileContentsMap.h>

#include <cstring>

class Localizer
{
private:
    FileContentsMap map;
    StorageDevice* storage_dev;
    
    char locale[6];

    bool is_localization_file_open = false;

public:
    Localizer(StorageDevice* storage_dev, const char* locale = "en_us");
    ~Localizer();

    inline void SetLocale(const char* new_locale)
    {
        strncpy(locale, new_locale, 5);
        locale[2] = '_';
    }

    void OpenLocalizationFile();
    void CloseLocalizationFile();
    [[nodiscard]] UniqueArray<char> LoadLocalizedText(const char* key);
};