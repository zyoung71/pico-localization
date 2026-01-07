#include <localization/Localizer.h>

Localizer::Localizer(StorageDevice* storage_dev, const char* locale)
    : map(storage_dev), storage_dev(storage_dev)
{
    SetLocale(locale);
}

Localizer::~Localizer()
{
    CloseLocalizationFile();
}

void Localizer::OpenLocalizationFile()
{
    if (storage_dev->IsFileOpen())
    {
        storage_dev->CloseFile();
    }
    char filename[32];
    snprintf(filename, 32, "/.locale/%s.lang", locale);

    storage_dev->OpenFile(filename, OPEN_EXISTING | READ);
    is_localization_file_open = true;
}

void Localizer::CloseLocalizationFile()
{
    if (is_localization_file_open)
    {
        storage_dev->CloseFile();
        is_localization_file_open = false;
    }
}

UniqueArray<char> Localizer::LoadLocalizedText(const char* key)
{
    if (!is_localization_file_open)
    {
        OpenLocalizationFile();
    }

    return map.GetValue(key);
}