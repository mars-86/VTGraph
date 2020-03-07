#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include "ui/ui.h"
#include "gfx/gfx.h"
#include "os/os.h"
#include "vterm/vterm.h"

#include <thread>
#include <ctime>

#define PI 3.14

int main(int argc, char* argv[]) {

    os::ContainerSize size;
    os::_init_instance(&size);

	vterm::VTerm vt;
    // std::cout << "\x1B[?25h";
	// vt.set_cursor_visibility(VTERM_CURSOR_HIDE);
	vt.set_title("VTERM");

	ui::Frame frame(size.cs_col, size.cs_row);
	ui::TitleBar tbar("I'm a title bar", frame.get_max_width(), ui::POSITION::TOP);
	ui::Grid grid(frame.get_max_height() - 6, 10);
    ui::EuclideanSpace eusp2d(ui::EUCLIDEAN_CONTEXT::_2D, frame.get_max_width(), frame.get_max_height() - 6, ui::POSITION::TOP);
    //ui::EuclideanSpace eusp3d(ui::EUCLIDEAN_CONTEXT::_3D, 10, frame.get_max_height() - 6, ui::POSITION::TOP);
	frame.add("titlebar", tbar);
	frame.add("grid", grid);
	frame.add("eusp_2d", eusp2d);
	//frame.add("eusp_3d", eusp3d);
	frame.visible();
	//std::cout << "W: " << frame.get_max_width() << std::endl << "H: " << frame.get_max_height() << std::endl;

    int exec = 0;
    if (exec) {
        ui::Canvas canvas(size.cs_row, size.cs_col, ui::UNSIGNED);
        canvas.set_cursor_visibility(VTERM_CURSOR_HIDE);
        std::string axis("xy");
        //canvas.show_axis(axis);
        std::vector<ui::Point2D> sn;
        std::vector<ui::Point2D> parab;
        double n = 1;
        gfx::Rect rect(25, 25, 20, 10, { 50, 150, 200, 0 });
        gfx::Square sq(60, 25, 25, { 150, 170, 200 });
        gfx::Line line(70, 60, 40, 40, { 230, 40, 86 });
        gfx::Line line2(40, 20, 70, 40, { 230, 40, 86 });
        gfx::Line line3(10, 10, 70, 11, { 230, 40, 86 });
        gfx::Line line4(1, 70, 130, 70, { 230, 40, 86 });
        gfx::Circle circle(35, 35, 30, { 230, 40, 86 });
        gfx::Ellipse elipse1(45, 40, 3, 10, { 230, 40, 86 });
        gfx::Ellipse elipse2(25, 40, 3, 10, { 230, 40, 86 });
        gfx::Parable parable(33, 20, 0, 0, { 230, 40, 86 });
        //void (CCanvas:: * dw)(gfx::Shape2D&) = &CCanvas::draw;
        std::srand((time_t)std::time((time_t*)nullptr));

        /*for (;;) {
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
            //canvas.draw(sn);
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
    std::getchar();

    return 0;
}
