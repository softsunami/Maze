#ifndef A1_MAZE_VIEW_MAINWINDOW_H_
#define A1_MAZE_VIEW_MAINWINDOW_H_

#include <QAbstractButton>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QFileDialog>
#include <QIntValidator>
#include <QMainWindow>
#include <QMimeData>
#include <QPainter>
#include <QTabBar>

#include "./ui_mainwindow.h"
#include "CavePainter/cavepainter.h"
#include "MazePainter/mazepainter.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 signals:
  void UploadMaze(std::string file_name);
  void GenerateMaze(unsigned int rows, unsigned int cols);
  void SaveMaze(std::string file_name);
  void FindPath(Point from, Point to);
  void UploadCave(std::string file_name, int limit_birth, int limit_death);
  void GenerateCave(int init_chance, unsigned int rows, unsigned int cols);
  void NextGeneration(int limit_birth, int limit_death);

 public slots:
  void DrawMaze(MazeType* maze);
  void DrawPath(std::vector<Point> path);
  void DrawCave(CaveType* cave);
  void CaveStopGeneration_();

 private slots:
  void SwitchApplicationTab_(QAbstractButton* button);
  void HideTabs_();
  void UpdateDisplayWidgets_();
  void EmitUploadMaze_();
  void EmitGenerateMaze_();
  void EmitSaveMaze_();
  void EmitUploadCave_();
  void EmitGenerateCave_();
  void CaveStartGeneration_();

 private:
  Ui::MainWindow* ui_;
  MazePainter* maze_painter_{nullptr};
  CavePainter* cave_painter_{nullptr};
  QTimer* timer_{nullptr};

  void InitView_();
};

}  // namespace s21

#endif  // A1_MAZE_VIEW_MAINWINDOW_H_
