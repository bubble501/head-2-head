import {BrowserModule} from '@angular/platform-browser';
import {NgModule} from '@angular/core';
import {AppComponent} from './app.component';
import {GamesModule} from "./games/games.module";
import {TakerModule} from "./taker/taker.module";
import {WagersModule} from "./wagers/wagers.module";

@NgModule({
  declarations: [
    AppComponent
  ],
  imports: [
    BrowserModule,
      GamesModule,
      TakerModule,
      WagersModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
