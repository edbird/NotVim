#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm/textview.h>
//#include <gtkmm/button.h>

#include <iostream>
#include <fstream>


class MainWindow
{


    public:

    MainWindow()
        // :
        : _unhandled_keys_ostream_("unhandled_keys.txt")
    {
        _window_.set_default_size(600, 400);
        _window_.set_title("NotVim");
        _window_.set_border_width(0);
        _window_.add(_textview_);
        //window.add(_button_);

        Glib::RefPtr<Gtk::TextBuffer> textbuffer_rp{_textview_.get_buffer()};
        textbuffer_rp->set_text("welcome to NotVim !");

        _textview_.set_monospace();

        //_textview_.add_events(Gdk::KEY_PRESS_MASK);

        //_textview_.signal_ 
        _window_.add_events(Gdk::KEY_PRESS_MASK);
        
        _window_.show_all_children();

        //_button_.show();
        //_textview_.show();
    }

    ~MainWindow()
    {
        _unhandled_keys_ostream_.flush();
        _unhandled_keys_ostream_.close();
    }   

    Gtk::Window &get_window()
    {
        return _window_;
    }

    protected:

    bool on_key_press_event(GdkEventKey* event)
    {
        std::cout << "some keypress event" << std::endl; 

        if
        (
            (event->keyval == GDK_KEY_H) &&
            ((event->state & (GDK_SHIFT_MASK | GDK_CONTROL_MASK | GDK_MOD1_MASK) == GDK_CONTROL_MASK))
        )
        {
            std::cout << "Hello world!" << std::endl;
        }

        if
        (
            (event->keyval == GDK_KEY_C) &&
            ((event->state & (GDK_SHIFT_MASK | GDK_CONTROL_MASK | GDK_MOD1_MASK) == GDK_CONTROL_MASK))
        )
        {
            signal_textview_CTRL_C();
        }
        else if
        ( 
            (event->keyval == GDK_KEY_V) &&
            ((event->state & (GDK_SHIFT_MASK | GDK_CONTROL_MASK | GDK_MOD1_MASK) == GDK_CONTROL_MASK))
        )
        {
            signal_textview_CTRL_V();
        }
        else
        {
            _unhandled_keys_ostream_ << event->keyval << " " << event->state << std::endl;
        }

        return true;
    }

    void signal_textview_CTRL_C()
    {
        _text_register_0_ = "some text gets put here";
    }

    void signal_textview_CTRL_V()
    {
        // TODO: override to get this functionality
        //_textview_.set_text(_text_register_0_);
        
        Glib::RefPtr<Gtk::TextBuffer> textbuffer_rp{_textview_.get_buffer()};
        textbuffer_rp->set_text(_text_register_0_);
    }

    private:

    Gtk::Window _window_;
    Gtk::TextView _textview_;
    //Gtk::Button _button_;

    Glib::ustring _text_register_0_;

    std::ofstream _unhandled_keys_ostream_;

};

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

    MainWindow mainwindow;

    return app->run(mainwindow.get_window());
}
