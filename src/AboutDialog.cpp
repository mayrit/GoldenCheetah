/*
 * Copyright (c) 2013 Mark Liversedge (liversedge@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "AboutDialog.h"
#include "GcUpgrade.h"
#include "GcCrashDialog.h"

AboutDialog::AboutDialog(MainWindow *mainWindow, QDir home) : mainWindow(mainWindow), home(home)
{
    setWindowTitle(tr("About GoldenCheetah"));

    aboutPage = new AboutPage(mainWindow, home);
    versionPage = new VersionPage(mainWindow, home);
    contributorsPage = new ContributorsPage(mainWindow, home);
#ifndef GC_VERSION
    configPage = new ConfigPage(mainWindow, home);
#endif

    tabWidget = new QTabWidget;
    tabWidget->setContentsMargins(0,0,0,0);
    tabWidget->addTab(aboutPage, tr("About"));
    tabWidget->addTab(versionPage, tr("Version"));
#ifndef GC_VERSION
    tabWidget->addTab(configPage, tr("Config"));
#endif
    tabWidget->addTab(contributorsPage, tr("Contributors"));

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);

    //mainLayout->setContentsMargins(0,0,0,0);
    //mainLayout->setSpacing(0);

    setLayout(mainLayout);
}


//
// About page
//
AboutPage::AboutPage(MainWindow *main, QDir home) : main(main), home(home)
{
    QLabel *text;
    text=new QLabel(this);
    text->setContentsMargins(0,0,0,0);
    text->setText(
              tr(
                "<center>"
                "<h2>GoldenCheetah</h2>"
                "Cycling Power Analysis Software<br>for Linux, Mac, and Windows"
                "<p>GoldenCheetah is licensed under the<br>"
                "<a href=\"http://www.gnu.org/copyleft/gpl.html\">GNU General "
                "Public License</a>."
                "<p>Source code can be obtained from<br>"
                "<a href=\"http://goldencheetah.org/\">"
                "http://goldencheetah.org/</a>."
                "<p>Activity files and other data are stored in<br>"
                "<a href=\"%1\">%2</a>"
                "<p>Trademarks used with permission<br>"
                "TSS, NP, IF courtesy of <a href=\"http://www.peaksware.com\">"
                "Peaksware LLC</a>.<br>"
                "BikeScore, xPower courtesy of <a href=\"http://www.physfarm.com\">"
                "Physfarm Training Systems</a>.<br>"
                "Virtual Speed courtesy of Tom Compton <a href=\"http://www.analyticcycling.com\">"
                "Analytic Cycling</a>."
                "</center>"
                )
                .arg(QString(QUrl::fromLocalFile(main->home.absolutePath()).toEncoded()))
                .arg(main->home.absolutePath().replace(" ", "&nbsp;"))
    );

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->addWidget(text);
    setLayout(mainLayout);
}

//
// Version page
//
VersionPage::VersionPage(MainWindow *main, QDir home) : main(main), home(home)
{
    QLabel *text;
    text=new QLabel(this);
    text->setContentsMargins(0,0,0,0);
    text->setText(GcCrashDialog::versionHTML());
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->addWidget(text);

    setLayout(mainLayout);
}

//
// Contributors page
//
ContributorsPage::ContributorsPage(MainWindow *main, QDir home) : main(main), home(home)
{
    QStringList contributors;
    contributors.append("Alejandro Martinez");
    contributors.append("Andrew Bryson");
    contributors.append("Andy Froncioni");
    contributors.append("Austin Roach");
    contributors.append("Berend De Schouwer");
    contributors.append("Bruno Assis");
    contributors.append("Chris Cleeland");
    contributors.append("Claus Assmann");
    contributors.append("Dag Gruneau");
    contributors.append("Damien Grauser");
    contributors.append("Darren Hague");
    contributors.append("Dean Junk");
    contributors.append("Eric Brandt");
    contributors.append("Eric Murray");
    contributors.append("Frank Zschockelt");
    contributors.append("Gareth Coco");
    contributors.append("Greg Lonnon");
    contributors.append("Ilja Booij");
    contributors.append("Jaime Jofre");
    contributors.append("Jamie Kimberley");
    contributors.append("Jim Ley");
    contributors.append("John Ehrlinger");
    contributors.append("Jon Escombe");
    contributors.append("Josef Gebel");
    contributors.append("Julian Baumgartner");
    contributors.append("Julian Simioni");
    contributors.append("Justin Knotzke");
    contributors.append("Keisuke Yamaguchi");
    contributors.append("Ken Sallot");
    contributors.append("Luke NRG");
    contributors.append("Magnus Gille");
    contributors.append("Marc Boudreau");
    contributors.append("Mark Liversedge");
    contributors.append("Mark Rages");
    contributors.append("Mitsukuni Sato");
    contributors.append("Ned Harding");
    contributors.append("Patrick McNerthney");
    contributors.append("Rainer Clasen");
    contributors.append("Robb Romans");
    contributors.append("Robert Carlsen");
    contributors.append("Roberto Massa");
    contributors.append("Ron Alford");
    contributors.append("Satoru Kurashiki");
    contributors.append("Sean Rhea");
    contributors.append("Steven Gribble");
    contributors.append("Thomas Weichmann");
    contributors.append("Walter B&#252;rki");

    QString contributorsTable = "<center><table><tr>";
    for (int i=0;i<contributors.count();i++){
        contributorsTable.append("<td><center>"+contributors.at(i)+"</center></td>");
        if ((i+1) % 2 == 0)
            contributorsTable.append("</tr><tr>");
    }
    contributorsTable.append("</tr></table></center>");

    QLabel *text;
    text=new QLabel(this);
    text->setContentsMargins(0,0,0,0);
    text->setText(contributorsTable);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->addWidget(text);

    setLayout(mainLayout);
}

ConfigPage::ConfigPage(MainWindow *main, QDir home) : main(main), home(home)
{
    QTextEdit *text = new QTextEdit(this);
    text->setAutoFillBackground(false);
#ifdef Q_OS_MAC
    text->setAttribute(Qt::WA_MacShowFocusRect, 0);
#endif
    text->setFrameStyle(QFrame::NoFrame);
    text->setContentsMargins(0,0,0,0);

    QFile file(":gcconfig.pri");
    file.open(QFile::ReadOnly);
    QTextStream stream(&file);
    QString contents = stream.readAll();
    file.close();
    text->setText(contents);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->addWidget(text);

    setLayout(mainLayout);
}

