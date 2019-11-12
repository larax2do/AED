


#include <stdlib.h>
#include <gtk/gtk.h>
//#include "ArbolAVL.h"
#include "SplayTree.h"
#include <string>

struct datis
{
    GObject *box;
    SplayTree<std::string> arbo;
    GtkWidget *img;
    GObject *gri;
    datis(GObject *b,GtkWidget *i,GObject *g,SplayTree<std::string> &a):box{b},arbo{a},img{i},gri{g}{}
};
static void agregar (GtkWidget *widget, struct datis *data)
{
    //(GtkLabel*)by_ptr->widgets.label
    const gchar *buffer=gtk_entry_get_text(GTK_ENTRY((GObject *)data->box));
    //std::string testt="1000";
    std::string temp(buffer);
    data->arbo.insertar(temp);
    data->arbo.mostrar();

    gtk_image_set_from_file (GTK_IMAGE(data->img),"ARBOL.png");

    //data->img = gtk_image_new_from_file ("ARBOL.png");
    g_print (buffer);
    //gtk_paned_add2(GTK_PANED(data->gri),GTK_WIDGET(data->img));
    //gtk_widget_show(GTK_WIDGET(data->img));

}

static void quitar (GtkWidget *widget, struct datis *data)
{
    //(GtkLabel*)by_ptr->widgets.label
    const gchar *buffer=gtk_entry_get_text(GTK_ENTRY((GObject *)data->box));
    //std::string testt="1000";
    std::string temp(buffer);
    data->arbo.remover(temp);
    data->arbo.mostrar();

    gtk_image_set_from_file (GTK_IMAGE(data->img),"ARBOL.png");

    //data->img = gtk_image_new_from_file ("ARBOL.png");
    g_print (buffer);
    //gtk_paned_add2(GTK_PANED(data->gri),GTK_WIDGET(data->img));
    //gtk_widget_show(GTK_WIDGET(data->img));

}



/*static void printButton (GtkWidget *widget, gpointer   data)
{

    const gchar *buffer=gtk_entry_get_text(GTK_ENTRY((GObject *)data));
    g_print (buffer);
}
*/
/*
static void SbMainExit(GtkWidget* window,gpointer data)
{
    printf("tri bli bli bli /n");
    gtk_main_quit();
}

static gboolean FngBolDeleteEvent(GtkWidget* window,GdkEvent *event, gpointer data)
{
    printf("Delete eventttttt\n");
    if(event->type==GDK_DELETE)
        return FALSE;
    else
        return TRUE;
}
*/
int main (int argc, char *argv[])
{
    GtkBuilder *builder;
    GObject *window;
    GObject *button;
    GObject *box1;
    GObject *grilla;
    GtkWidget *imagen;
    //GObject *img;
    GError *error = NULL;
    /////////77



    ///////////
    gtk_init (&argc, &argv);

    /* Construct a GtkBuilder instance and load our UI description */
    builder = gtk_builder_new ();
    if (gtk_builder_add_from_file (builder, "inter.glade", &error) == 0)
    {
        g_printerr ("Error loading file: %s\n", error->message);
        g_clear_error (&error);
        return 1;
    }

    window = gtk_builder_get_object (builder, "window1");
    box1=gtk_builder_get_object(builder,"entry1");



    SplayTree<std::string> arbolito;
    arbolito.mostrar();

    imagen = gtk_image_new_from_file ("ARBOL.png");
    grilla=gtk_builder_get_object(builder,"vpaned1");
    gtk_paned_add2(GTK_PANED(grilla),GTK_WIDGET(imagen));

    datis *datos=new datis{box1,imagen,grilla,arbolito};

    button = gtk_builder_get_object (builder, "button1");
    g_signal_connect (button, "clicked", G_CALLBACK (agregar), datos);

    button= gtk_builder_get_object (builder, "button2");
    g_signal_connect (button, "clicked", G_CALLBACK (quitar), datos);

    gtk_builder_connect_signals(builder,NULL);
    g_object_unref(G_OBJECT(builder));

    gtk_widget_show(GTK_WIDGET(window));
    gtk_widget_show(GTK_WIDGET(imagen));





    //g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);



    //GtkWidget* window;
    //GtkWidget* button;
/*
    gtk_init(&argc,&argv);

    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"titulo de la ventana");
    gtk_window_set_default_size(GTK_WINDOW(window),250,250);
    gtk_container_set_border_width(GTK_CONTAINER(window),5);

    gtk_widget_show(window);

    g_signal_connect (G_OBJECT(window),"destroy",G_CALLBACK(SbMainExit),NULL);

    g_signal_connect (G_OBJECT(window),"delete_event",G_CALLBACK(FngBolDeleteEvent),NULL);

    button=gtk_button_new_with_label("cerrarrr");

    gtk_button_set_relief(GTK_BUTTON(button),GTK_RELIEF_NONE);

    g_signal_connect_swapped(G_OBJECT(button),"clicked",G_CALLBACK(gtk_widget_destroy),window);

    gtk_container_add(GTK_CONTAINER(window),button);
    gtk_widget_show(button);
*/
    gtk_main();
    //datos->arbo.insertar("1");


  return 0;
}
