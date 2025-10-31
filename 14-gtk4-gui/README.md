# Module 14: GTK4 GUI Programming 🖼️

Create graphical user interfaces with GTK4!

## 📚 What You'll Learn

1. Introduction to GTK4
2. Setting up GTK4 development
3. Creating windows and widgets
4. Event handling
5. Building simple GUI applications

## 🪟 Basic GTK4 Window

```c
#include <gtk/gtk.h>

static void on_activate(GtkApplication *app) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Hello GTK4");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    
    GtkWidget *label = gtk_label_new("Hello, World!");
    gtk_window_set_child(GTK_WINDOW(window), label);
    
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
    GtkApplication *app = gtk_application_new("com.example.app", 
                                               G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
```

## 🔘 Button with Callback

```c
static void on_button_clicked(GtkButton *button, gpointer data) {
    g_print("Button clicked!\n");
}

GtkWidget *button = gtk_button_new_with_label("Click Me");
g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
```

## 📦 Building

```bash
gcc $(pkg-config --cflags gtk4) -o myapp myapp.c $(pkg-config --libs gtk4)
```

## 🔜 Next Module

[Module 15: Game Development Projects](../15-game-projects/README.md)
