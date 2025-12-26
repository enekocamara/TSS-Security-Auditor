//quick test to get user information on a screen

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <TSS-Security-Auditor/include/windows.hpp>
#include <ntsecapi.h>
#include <lm.h>
#include <CLI/CLI.hpp>
#include <iostream>
#include <iostream>

int main(int argc, char** argv) {

    CLI::App app{ "My tool" };

    auto hello = app.add_subcommand("hello", "Say hello");
    auto goodbye = app.add_subcommand("goodbye", "Say goodbye");



    CLI11_PARSE(app, argc, argv);
    
    if (*hello) {
        std::cout << "Hello!\n";
    }
    else if (*goodbye) {
        std::cout << "Goodbye!\n";
    }

    /*
    NET_API_STATUS NetLocalGroupGetMembers(
        LPCWSTR servername,
        LPCWSTR localgroupname,
        DWORD   level,
        LPBYTE  *bufptr,
        DWORD   prefmaxlen,
        LPDWORD entriesread,
        LPDWORD totalentries,
        LPDWORD resumehandle
        );
    */
    LPCWSTR server_name = nullptr;//local machine
    LPCWSTR local_group_name = L"Administrators";
    DWORD level = 2;
    LPLOCALGROUP_MEMBERS_INFO_2 output_bufptr = nullptr;//netlocalgroupgetnumbers asigns value
    DWORD prefered_max_len = MAX_PREFERRED_LENGTH;//system decides
    DWORD entry_count;
    DWORD total_available_entry_count;
    PDWORD_PTR resume_handle = nullptr;//optional value for pagination


    NET_API_STATUS result = NetLocalGroupGetMembers(
        server_name,
        local_group_name,
        level,
        (LPBYTE*)(&output_bufptr),
        prefered_max_len,
        &entry_count,
        &total_available_entry_count,
        resume_handle
        );
    if (result != NERR_Success) {
        std::cerr << "Error\n";
    }
    for (DWORD i = 0; i < entry_count; ++i) {
        wprintf(L"%s\n", output_bufptr[i].lgrmi2_domainandname);
    }
    NetApiBufferFree(output_bufptr);

    Fl_Window* win = new Fl_Window(300, 180, "Hello FLTK");
    Fl_Box* box = new Fl_Box(20, 40, 260, 100, "Hello World!");
    win->end();
    win->show();
    return Fl::run();
}