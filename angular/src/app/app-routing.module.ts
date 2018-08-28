import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import {RouterModule, Routes} from '@angular/router';
import {TestComponent} from './test/test.component';

const routes: Routes = [
  { path: 'make-bets', component: TestComponent },
  { path: 'take-bets', component: TestComponent },
  { path: 'collect', component: TestComponent }
];

@NgModule({
  imports: [
    CommonModule,
    RouterModule.forRoot(routes)
  ],
  exports: [ RouterModule ]
})
export class AppRoutingModule { }



