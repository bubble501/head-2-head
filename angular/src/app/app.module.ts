import {BrowserModule} from '@angular/platform-browser';
import {NgModule} from '@angular/core';
import {AppComponent} from './app.component';
import {GamesModule} from './games/games.module';
import {TakerModule} from './taker/taker.module';
import {WagersModule} from './wagers/wagers.module';
import { AppRoutingModule } from './/app-routing.module';
import { TestComponent } from './test/test.component';

@NgModule({
  declarations: [
    AppComponent,
    TestComponent
  ],
  imports: [
    BrowserModule,
      GamesModule,
      TakerModule,
      WagersModule,
      AppRoutingModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
