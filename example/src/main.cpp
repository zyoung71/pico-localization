#include <pico/stdio.h>

#include <localization/Localizer.h>

int main()
{
    stdio_init_all();

    StorageDevice* dev;

    Localizer localizer(dev);

    localizer.OpenLocalizationFile();

    auto greeting = localizer.LoadLocalizedText("ui.greeting");
    auto goodbye = localizer.LoadLocalizedText("ui.goodbye");
    auto currency = localizer.LoadLocalizedText("symbol.currency");

    printf("Greeting: %s\tGoodbye: %s\t Currency: %s", greeting.array.get(), goodbye.array.get(), currency.array.get());

    while (1)
    {
        tight_loop_contents();
    }
}