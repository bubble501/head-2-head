import {BrowserModule} from '@angular/platform-browser';
import {NgModule} from '@angular/core';
import {AppComponent} from './app.component';
import {TakerModule} from './taker/taker.module';
import { AppRoutingModule } from './app-routing.module';
import {MakerModule} from "./maker/maker.module";


@NgModule({
  declarations: [
    AppComponent
  ],
  imports: [
    BrowserModule,
    MakerModule,
    TakerModule,
    AppRoutingModule
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }
