#ifndef BURNT_CONFIG_H
#define BURNT_CONFIG_H
#include <string>
#include <glib.h>
#include <iostream>
using namespace std;

typedef struct
{
    gsize Size;
    gboolean RandTest;
    gchar **DecTypes;
    gdouble *DecValues;
}ClassTree_s;

typedef struct
{
    int Min;
    int Max;
} BuffSizes_s;

typedef struct
{
    gboolean PrintFilename;
    gboolean PrintDebug;
    gboolean PrintBuffer;
}DebugMessages_s;

typedef struct
{
    gboolean Enable;
    gboolean Sync;
}Snapshot_s;

class BurntConfig
{
    public:
        BurntConfig(const gchar *config_file_str);
        ~BurntConfig();
        ClassTree_s *ClassTree;
        BuffSizes_s *BuffSizes;
        DebugMessages_s *DebugMessages;
        Snapshot_s *Snapshot;
        void print_config();
        void print_class_tree();
        void print_buff_sizes();
        void print_debug_messages();
        void print_snapshot();

    private:
        void init_class_tree();
        void init_buffer_sizes();
        void init_debug_messages();
        void init_snapshot();
        void init_all();
        string config_file_str;
        GKeyFile* gkf;
};


#endif