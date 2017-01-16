#include "BurntConfig.h"

BurntConfig::BurntConfig(const gchar *config_file_str)
{
    // 1. Check to see if exists, open file
    this->gkf = g_key_file_new();
    try
    {
        if (!g_key_file_load_from_file(gkf, config_file_str, G_KEY_FILE_NONE, NULL))
        {
            throw;
        }
    }
    catch(...)
    {
        perror("Unable to open file!\n");
        g_key_file_free (gkf);
        throw;
    }

    this->ClassTree = g_slice_new(ClassTree_s);
    this->BuffSizes = g_slice_new(BuffSizes_s);
    this->DebugMessages = g_slice_new(DebugMessages_s);
    this->Snapshot = g_slice_new(Snapshot_s);
    this->config_file_str = config_file_str;

    init_all();
    print_config();
}



void BurntConfig::init_class_tree()
{
    gsize len_type;
    gsize len_value;
    this->ClassTree->DecTypes = g_key_file_get_string_list(gkf, "ClassTree", "DecTypes", &len_type, NULL);
    this->ClassTree->DecValues = g_key_file_get_double_list (gkf, "ClassTree", "DecValues", &len_value, NULL);
    this->ClassTree->RandTest = g_key_file_get_boolean(gkf, "ClassTree", "RandTest", NULL);
    if(len_type != len_value)
    {
        perror("Classification tree definition error. DecTypes and DecValues length do not match.");
        throw;
    }
    else
    {
        this->ClassTree->Size = len_value;
    }
}

void BurntConfig::init_buffer_sizes()
{
    this->BuffSizes->Min = g_key_file_get_integer(gkf, "BuffSizes", "Min", NULL);
    this->BuffSizes->Max = g_key_file_get_integer(gkf, "BuffSizes", "Max", NULL);
}

void BurntConfig::init_debug_messages()
{
    this->DebugMessages->PrintFilename = g_key_file_get_boolean(gkf, "DebugMessages", "PrintFilename", NULL);
    this->DebugMessages->PrintDebug = g_key_file_get_boolean(gkf, "DebugMessages", "PrintDebug", NULL);
    this->DebugMessages->PrintBuffer = g_key_file_get_boolean(gkf, "DebugMessages", "PrintBuffer", NULL);
}

void BurntConfig::init_snapshot()
{
    this->Snapshot->Enable = g_key_file_get_boolean(gkf, "Snapshot", "Enable", NULL);
    this->Snapshot->Sync = g_key_file_get_boolean(gkf, "Snapshot", "Sync", NULL);
}

void BurntConfig::init_all()
{
    init_class_tree();
    init_buffer_sizes();
    init_debug_messages();
    init_snapshot();
}
BurntConfig::~BurntConfig()
{
    g_slice_free(ClassTree_s, this->ClassTree);
    g_slice_free(BuffSizes_s, this->BuffSizes);
    g_slice_free(DebugMessages_s, this->DebugMessages);
    g_slice_free(Snapshot_s, this->Snapshot);

    g_key_file_free (gkf);
}


void BurntConfig::print_config()
{
    cout << "--==BuRnT Configuration File==--" << endl;
    cout << "Configuration Filename: " << config_file_str << endl;
    cout << "Classification Tree" << endl;
    print_class_tree();
    cout << "Buffer Sizes" << endl;
    print_buff_sizes();
    cout << "Debug Messages" << endl;
    print_debug_messages();
    cout << "Snapshot Settings" << endl;
    print_snapshot();
    cout << "\n\n";
}

void BurntConfig::print_class_tree()
{
    cout << "\tRandTest: " << ClassTree->RandTest << endl;
    for(int i = 0; i < ClassTree->Size; i++)
    {
        cout << "\t<" << ClassTree->DecTypes[i] << ", "
             << ClassTree->DecValues[i] << ">" << endl;
    }
}

void BurntConfig::print_buff_sizes()
{
    cout << "\tMin Size: " << BuffSizes->Min << endl;
    cout << "\tMax Size: " << BuffSizes->Max << endl;
}

void BurntConfig::print_debug_messages()
{
    cout << "\tPrint Filename: " << DebugMessages->PrintFilename << endl;
    cout << "\tPrint Debug: " << DebugMessages->PrintDebug << endl;
    cout << "\tPrint Buffer: " << DebugMessages->PrintBuffer << endl;
}

void BurntConfig::print_snapshot()
{
    cout << "\tEnable: " << Snapshot->Enable << endl;
    cout << "\tSync: " << Snapshot->Sync << endl;
}