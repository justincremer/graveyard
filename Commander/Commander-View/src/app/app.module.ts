import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { FormsModule } from '@angular/forms';
import { HttpModule } from '@angular/http';
import { CommandsListComponent } from './commands-list/commands-list.component';
import { AddUpdateCommandsComponent } from './add-update-commands/add-update-commands.component';
import { CommandsService } from './commands.service';
import { RouterModule, Routes } from '@angular/router';
import { HttpClientModule } from '@angular/common/http';

const appRoutes: Routes = [
  {
    path: '',
    component: AppComponent,
  }
]

@NgModule({
  declarations: [
    AppComponent,
    CommandsListComponent,
    AddUpdateCommandsComponent
  ],
  imports: [
    BrowserModule,
    RouterModule.forRoot(appRoutes),
    AppRoutingModule,
    FormsModule,
    HttpModule,
    HttpClientModule
  ],
  providers: [CommandsService],
  bootstrap: [AppComponent]
})
export class AppModule { }
