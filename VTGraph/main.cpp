#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include "ui/ui.h"
#include "gfx/gfx.h"
#include "os/os.h"
#include "vterm/vterm.h"
#include "ui/graphic.h"

#include <thread>
#include <ctime>

#define PI 3.14

LRESULT CALLBACK term_proc(HANDLE, UINT, WPARAM, LPARAM);

int main(int argc, char* argv[]) {

    std::getchar();
    os::ContainerSize size;
    os::_init_instance(&size);
    std::cout << size.cs_col << size.cs_row << std::endl;
    // std::getchar();
    // vterm::VTerm vt;
    // std::cout << "\x1B[?25h";
	// vt.set_cursor_visibility(VTERM_CURSOR_HIDE);
	// vt.set_title("VTERM");
    std::vector<std::string> head = { "X", "Y" };
    std::vector<std::vector<std::string>> data = { {"1", "2"}, {"5", "10"}, {"3", "4"} };

    // std::string bra = u8"\u280A";
    // std::cout << bra;
    std::vector<gfx::Point2D> sine;
    double n1 = 5;
    for (double i = 0; i < PI * 4; i += .03) {
        sine.push_back({ (int)(n1), (int)(25 + 10 * (sin(i))) });
        // canvas.draw(line2);
        //x1 = (int)n;
        //y1 = (int)(80 + 50 * sin(i));
        n1 += 0.314;
    }

    gfx::Line line(70, 60, 40, 40, { 230, 40, 86 });
    gfx::Rect rect(25, 25, 20, 10, { 50, 150, 200, 0 });
    gfx::Circle circle(50, 15, 10, { 230, 40, 86 });
    gfx::Parable parable(33, 20, 0, 0, { 230, 40, 86 });
    gfx::Parable parable2(100, 20, 115, 115, { 230, 40, 86 });
    gfx::Line line3(70, 10, 200, 30, { 230, 40, 86 });
    gfx::Square sq(60, 25, 25, { 150, 170, 200 });

    ui::Graphic gr(nullptr, size.cs_col, size.cs_row);
    //gr.draw({{10, 10}, {11, 10}, {12, 10}, {13, 10}, {14, 10}, {15, 10}, {16, 10}, {17, 10}, {18, 10}, {19, 10}});
    //gr.draw({{10, 10}, {11, 11}, {12, 12}, {13, 13}, {14, 14}, {15, 15}, {16, 16}, {17, 17}, {18, 18}, {19, 19}});
    //gr.draw({{50, 10}, {49, 11}, {48, 12}, {47, 13}, {46, 14}, {45, 15}, {44, 16}, {43, 17}, {42, 18}, {41, 19}});

    gr.draw(sq);
    std::getchar();
    return 0;
    /*
    for (int i = 41; i < 100; ++i) {
        gr.draw(rect);
        Sleep(33);
        gr.erase(rect);
        rect.translate({i, 25});
    }
    return 0;
    for (int i = 0, j= 1; i < 2; ++i) {
        while (j < 81) {
            gfx::Line line3(1, 40, 200, j++, { 230, 40, 86 });
            gr.draw(line3);
            // Sleep(33);
            gr.erase(line3);
        }
        while (j > 1) {
            gfx::Line line3(1, 40, 200, j--, { 230, 40, 86 });
            gr.draw(line3);
            // Sleep(33);
            gr.erase(line3);
        }
    }
    return 0;
    std::getchar();
    */
	ui::Frame frame("VIRTUAL TERMINAL GRAPHICS", size.cs_col, size.cs_row);
	ui::EuclideanSpace eusp2d(ui::EUCLIDEAN_CONTEXT::_2D, frame.get_max_width() - 1, frame.get_max_height() - 2, ui::POSITION::TOP);
	eusp2d.draw_rect(5, 10, 20, 3, {150, 100, 200});
    frame.add("eusp_2d", eusp2d);
    frame.visible();
	/*ui::MenuItem file_new("New");
	ui::MenuItem file_open("Open");
	ui::MenuItem file_save("Save");
	ui::Menu file("File", {file_new, file_open, file_save});
	ui::Menu edit("Edit", {});
	ui::Menu help("Help", {});
	ui::MenuBar mbar(frame.get_max_width(), ui::POSITION::TOP);
	mbar.add_menu(file);
	mbar.add_menu(edit);
	mbar.add_menu(help);
    ui::Table table(frame.get_max_height() - 5, head, data);
    ui::EuclideanSpace eusp2d(ui::EUCLIDEAN_CONTEXT::_2D, frame.get_max_width() - 20, frame.get_max_height() - 5, ui::POSITION::TOP); */
    //ui::EuclideanSpace eusp3d(ui::EUCLIDEAN_CONTEXT::_3D, 10, frame.get_max_height() - 6, ui::POSITION::TOP);
    // eusp2d.draw_rect(1, 1, 5, 5, {0, 0, 0});
    // eusp2d.draw_line(-20, -5, 20, 10, { 0, 0, 0 });
    //eusp2d.draw_rect(5, 15, 20, 3, {0, 0, 0});
	// frame.add("menubar", mbar);
	// frame.add("table", table);
	// frame.add("eusp_2d", eusp2d);
	//frame.add("eusp_3d", eusp3d);
	// frame.visible();
	//std::cout << "W: " << frame.get_max_width() << std::endl << "H: " << frame.get_max_height() << std::endl;
    //std::cout << " " << g_win_tid << " " << pid;
    std::getchar();
    return 0;
    int exec = 1;
    if (exec) {
        ui::Canvas canvas(size.cs_col, size.cs_row);//, ui::UNSIGNED);
        std::cout << size.cs_row << " " << size.cs_col;
        canvas.set_cursor_visibility(VTERM_CURSOR_HIDE);
        canvas.show_axis("x");
        std::getchar();
        std::vector<ui::Point2D> sn;
        std::vector<ui::Point2D> parab;
        double n = 1;
        gfx::Rect rect(25, 25, 20, 10, { 50, 150, 200, 0 });

        gfx::Line line(70, 60, 40, 40, { 230, 40, 86 });
        gfx::Line line2(40, 20, 70, 40, { 230, 40, 86 });
        gfx::Line line3(10, 10, 70, 11, { 230, 40, 86 });
        gfx::Line line4(1, 70, 130, 70, { 230, 40, 86 });
        gfx::Circle circle(35, 35, 30, { 230, 40, 86 });
        gfx::Ellipse elipse1(45, 40, 3, 10, { 230, 40, 86 });
        gfx::Ellipse elipse2(25, 40, 3, 10, { 230, 40, 86 });
        gfx::Parable parable(33, 20, 0, 0, { 230, 40, 86 });
        //void (CCanvas:: * dw)(gfx::Shape2D&) = &CCanvas::draw;
        // std::srand((time_t)std::time((time_t*)nullptr));

        // canvas.draw(rect, 0);

        for (double i = 0; i < PI * 4; i += .1) {
                sn.push_back({ (int)(n), (int)(30 + 10 * (sin(i))) });
                // canvas.draw(line2);
                //x1 = (int)n;
                //y1 = (int)(80 + 50 * sin(i));
                n += 0.314;
            }
        canvas.draw(sn, 0);
        std::getchar();
        /*
        for (;;) {
            //int x1 = n, y1 = 80;
            gfx::Color color;
            for (double i = 0; i < PI * 4; i += .1) {
                sn.push_back({ (int)(n), (int)(30 + 10 * (sin(i))) });
                //canvas.draw(line2);
                //x1 = (int)n;
                //y1 = (int)(80 + 50 * sin(i));
                n += 0.314;
            }
            for (int x = 0; x < 9; ++x) {
                parab.push_back({ (19 + x * 4), (25 + ((x * x) - 8 * x)) });
            }
            n = 1;
            unsigned char r = 1 + std::rand() / ((RAND_MAX + 1u) / 255);
            unsigned char g = 1 + std::rand() / ((RAND_MAX + 1u) / 255);
            unsigned char b = 1 + std::rand() / ((RAND_MAX + 1u) / 255);
            color = { r, g, b };
            canvas.draw(sn);
            //canvas->draw(rect, sq, line);
            //canvas.draw(circle);
            //canvas.draw(elipse1);
            //canvas.draw(elipse2);
            //canvas.draw(parab, { 230, 40, 86 });
            //canvas.draw(line);
            //canvas.draw(line2);
            //canvas.draw(line3);
            //canvas.draw(line4);
            //canvas.draw(rect);
            //std::getchar();
            //canvas.translate(rect, 10, 10);
            for (int i = 0; i < 30; i += 2) {
                canvas.rotate(line4, i);
                std::this_thread::sleep_for(std::chrono::milliseconds(25));
            }
            for (int i = 30; i > -30; i -= 2) {
                canvas.rotate(line4, i);
                std::this_thread::sleep_for(std::chrono::milliseconds(25));
            }
            for (int i = -30; i < 0; i += 2) {
                canvas.rotate(line4, i);
                std::this_thread::sleep_for(std::chrono::milliseconds(25));
            }
            //for( int i = 0; i < 360; i += 10 ){
            //    canvas.rotate(rect, i);
            //    std::this_thread::sleep_for(std::chrono::milliseconds(30));
            //}
            //canvas.translate(rect, 10, 10);
            //canvas.draw(line4);
            //canvas.rotate(rect, 45);
            //std::getchar();
            //canvas.draw(sq);
            //std::getchar();
            canvas.flush();
            sn.clear();
        }*/
    }
	//while(1){

		//char buf[1];
		//int res;

		/* read scan code from stdin */
		//res = read(0, &buf[0], 1);
		/* keep reading til there's no more*/
		/*while (res >= 0) {
			switch (buf[0]) {
			case 0x01:*/
				/* escape was pressed */
				/*printf("%s", "ESC PRESS");
				break;
			case 0x81:*/
				/* escape was released */
				//break;
			/* process more scan code possibilities here! */
			//}
			//res = read(0, &buf[0], 1);
		//}
	//}
    std::getchar();

    return 0;
}
